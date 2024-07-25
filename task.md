# 云原生网络模型简介
https://www.cnblogs.com/bakari/p/10613710.html
## 1. Linux网络虚拟化与Docker容器网络
我们知道，运行于**Linux**上的Docker所实现的容器本身并不是像虚拟机一样，讲Host和VM通过hypervisor完全隔离开来，而是通过namespace技术限制了进程能“看到”的资源，例如进程的PID，工作目录以及网络接口；然后通过Cgroups限制单个容器所能占用的资源；最后通过分层镜像系统完成整个容器的构建。所以容器本身仍然是运行在OS上的一个**特殊的进程**，所有的容器共用一个Linux内核。
### (1) Network namespace
Linux虚拟化技术允许用户创建一个和主环境隔离的网络命名空间(netns)。每个netns拥有自己独立的网络栈，也即网卡，回环设备，路由表和iptables防火墙规则，一般来说我们希望不同的容器有不同的netns，从而避免复杂的网络配置。在Linux使用命令ip netns add XXX即可创建一个新的netns，创建之后系统会在/var/run/netns下生成一个挂载点存储该netns。
### (2) 网桥和veth-pair
不同的网络命名空间不能直接进行通信，因为他们没有互相连接的网卡，网络栈不知道该将数据转发到哪个IP，我们可以通过创建一个虚拟网络设备veth-pair进行连接，使用命令ip link add type veth创建一对网络接口，使用命令ip link set veth0 netns net0将一个接口分配给某个netns，分别将两个接口接到不同的netns之后，这两个netns之间就可以进行通信了，但是这样只能使得直接连接的两个netns进行通信，如果netns较多，这样的通信就会很麻烦。
现实中解决多机互联问题一般会引入一台交换机进行2层路由，在Linux中则以网桥作为虚拟交换机，利用指令ip link add br0 type bridge即可创建一个网桥，然后利用命令ip link set br-veth0 master br0，即可将veth-pair（veth-pair的图）的一端连接到网桥，另一端用命令ip link set veth0 netns ns1就可以接入netns，这样所有接入网桥的容器即可互相通信。
### (3) netfilter和iptables
https://www.cnblogs.com/chenxiao1/p/15748424.html
Netfilter是Linux内核中的一个软件框架，用于管理网络数据包。不仅具有网络地址转换（NAT）的功能，也具备数据包内容修改、以及数据包过滤等防火墙功能。
iptables是Netfilter在用户侧的接口的一种实现，iptables主要包括“四表五链”，分别是filter表，nat表，mangle表，raw表；五链分别是PREROUTING，POSTROUTING，FORWOAD，INPUT，OUTPUT。外网进入计算机的数据都会经这五链进行转发，主要关系如图1-2所示（加图），四表则对其制定规则，数据包过滤，数据包转发，地址转换（NAT）等功能。使用命令iptables -L -n -t tables_name即可查看不同表中的规则。
对于容器来说，在iptables中最重要的表主要是nat表，容器可以通过nat表的规则修改数据包的源地址和目标地址，配合路由表，从而控制不同netns之间以及容器对外界网络的通信。
### (4) Docker网络模型
容器是一个直接运行在操作系统上的特殊的进程，通过Linux命名空间技术实现资源隔离，对于网络资源也是如此。作为容器的一种实现，运行在**Linux**环境下的Docker容器主要Linux网络虚拟化技术实现不同容器之间的隔离，其主要网络模型包括桥接模式，主机（Host）模式以及无网络模式，不同模式之间最大的区别即是容器网络具体属于哪一个netns。


https://www.cnblogs.com/N3ptune/p/16607135.html
https://www.cnblogs.com/cheyunhua/p/16120797.html

#### a. 桥接模式
Docker在安装时会自动创建一个网桥（虚拟交换机）docker0，桥接模式下，Docker会为容器创建单独的一个netns，然后使用veth-pair技术，veth一头连接容器，一头连接docker创建的网桥。
容器所有到外部网络的连接，通过网桥之后，源地址都会被NAT成本地系统的IP地址，这是使用iptables的nat表的规则实现的。同一个网桥之间的容器也可以通过网桥进行通信。除了默认网桥docker0，用户也可以通过docker network create指令创建新的网桥，以实现容器的分组隔离通信。
#### b. Host模式
主机(Host)模式下，Docker会让容器进程使用宿主机的netns，此时容器进程能看到的接口就是宿主机能看到的接口，此时容器向外发送数据无需进行NAT，但是需要管理使用host模型的容器的端口，否则会出现端口冲突等问题。
#### c. 无网络模式
无网络(None)模式下，Docker容器拥有自己的netns，但是，并不为Docker容器进行任何网络配置。也就是说，这个Docker容器没有网卡、IP、路由等信息。需要我们自己为Docker容器添加网卡、配置IP等，是最灵活的一种网络模式。
#### d. Container模式
在创建容器时，如果使用了Container模式，Docker会要求用户指定一个容器，指定之后新创建的容器不会创建属于自己的netns，而是会直接加入指定容器的netns，与指定的容器共享网卡，网络IP等。

## 3. Kubernetes网络模型
Kubernetes是一个由Google设计的、开源的容器编排系统，用于自动化容器的部署，扩展和管理，现在由全球贡献者社区维护。
由于Kubernetes并不和Docker强绑定，Docker只是Kubernetes容器运行时的一个最常用的选项，因此其在设计之初就没有完全依赖于Docker的组件，Kubernetes拥有自己的一套网络组件container network interface(CNI)，其与Docker的网络模型既有共同点又有不同点，共同点在于都利用了Linux网络虚拟化技术；不同点在于Kubernetes经常以集群形式部署，因而需要引入一套跨节点的容器通信方案(例如Flannel方案)。

此外，Kubernetes的网络还要求Pod的IP地址是扁平化的，即：
a. 所有容器可以不经NAT而直接使用IP地址与其他**所有**容器通信。
b. 所有宿主机都可以不经NAT而直接使用IP地址和**所有**容器通信，反之亦然。
c. 容器自己“看到的”IP地址和其他宿主机/容器“看到的”IP地址相同。
### (1) Pod内网络和CNI插件
Pod是Kubernetes集群最小的调度单位，Kubernetes对服务的调度都会以Pod为最小单位进行，Pod内包含若干用户定义的、业务逻辑上耦合紧密的容器以及一个Infra容器。Pod在创建时，首先由k8s.gcr.io/pause镜像拉起一个Infra容器，根据已安装的cni插件配置Infra容器的netns，随后拉起其他容器，将这些容器以类似于Docker中的container模式加入到Infra容器的netns中，即所有Pod共享Infra容器的网络命名空间，因此他们对外的IP都是一致的。

由于Kubernetes存在不同的容器运行时的实现，因此Kubernetes并没有使用任何容器运行时的网络模型，其网络栈的配置主要是由CNI插件实现，部署Kubernetes完成后，我们可以在/opt/cni/bin目录下看到这些CNI插件，这些CNI插件有创建虚拟硬件的二进制文件，例如bridge，loopback，ptp(veth-pair)，也有负责分配IP地址，实现DHCP的IPAM插件，也有一些由社区维护的CNI插件，例如实现多节点无NAT容器通信的Flannel，通过iptables配置端口映射的portmap插件等。通过将这些插件部署到Infra容器中，然后令其他容器加入到Infra容器的netns，即完成了Pod内网络栈的配置。

### (2) service
Service是将运行在一个或一组Pod上的网络应用程序在Kubernetes集群内公开，Service就是访问Pod的接口，为集群内其他程序提供服务的方法。之所以需要Service，是因为一方面Pod的生命周期是短暂的，Pod很容易被删除，重启，调度从而导致IP地址的变更，另一方面是一组Pod之间总会有负载均衡的需求。

Service创建时会同时创建其所需要的Pod，这些被Service管理的Pod称为Service的Endpoints，在Kubernetes集群中，会为每个Service分配一个Virtual IP(VIP)，集群内可以通过VIP:Port的方式访问Service，为了使Service能够访问Pod，每个Node主机会开放一个端口称为NodePort，方便Service访问Pod。此外集群内其他Pod或节点也可以通过NodeIP:NodePort直接访问Pod，需要注意分配给Service的VIP仅能在集群内使用，集群外无法通过访问VIP:Port访问Service。
Service对Pod的代理是由kube-proxy组件实现的，当Service创建时，kube-proxy组件会读取Service的配置信息，然后使用iptables创建规则，该规则会将所有发送到Service VIP的数据包转到一个特殊的iptables链去处理，在iptables链中即可配置访问Service的流量NAT到不同Pod的概率，通过这种方式即可实现负载均衡。
### (3) 多节点互联：Flannel与VXLAN
之前提到Kubernetes要求Pod的IP地址是扁平化的，即集群内Pod拥有唯一的IP地址，但是不同节点之间的私有地址无法互相访问，为了解决这个问题，Kubernetes引入了Flannel插件作为CNI的基础插件之一来实现不同节点之间私有地址的相互访问。

Flannel的原理非常简单，它实际上是作为一个代理而存在，首先Flannel会在宿主机上创建一个TUN网络设备flannel0，一个进程flanneld并修改路由表，路由表中配置，如果是本地容器网段，则转发至cni0，如果是其他容器网段，则转发至flannel0。
当容器想要访问其他节点网段对应的容器时，由于没有匹配到容器netns的路由规则，因此按照默认规则转发至cni0网桥，然后匹配宿主机的路由规则，由于之前flannel已经修改了路由表，按照规则该数据包会被转发flannel0，flannel0将数据发送至flanneld，flanneld根据配置文件就知道了不同网段对应的宿主机IP，然后flanneld在原始数据包上封装一个UDP并发给对应宿主机上的flanneld进程，flanneld进程将数据包外层的UDP拆开并把数据包发送至flannel0设备，然后根据宿主机的路由规则转发至cni0，这就完成了不同节点之间私有地址的通信。

由于flanneld是运行在用户空间的进程，因此在转发过程中涉及了多次用户空间和内核空间的切换从而导致其通信效率较低，为了解决这个问题，Flannel插件引入了Linux虚拟化技术之中的VXLAN(virtual extensible LAN)技术。和flanneld原理类似，VXLAN模式下的Flannel插件仍然采用对原始数据包外部封装一个UDP包的方式，只不过这次是在内核空间中，首先Flannel会修改ARP表并创建一个VTEP(VXLAN tunnel end point)设备flannel.1，这个设备就代替了先前flanneld进程的作用，并且他是运行在内核空间中的！VTEP设备会修改原始数据包的目的MAC地址，改为目标宿主机的VTEP设备的MAC地址，然后交给Linux内核，Linux内核会再在原始数据包上封装一个VXLAN的私有协议头VXLAN header，随后向目标容器宿主机的VTEP设备发送一个UDP包，之后的过程类似，目标节点linux内核接到数据后会拆封VXLAN header，然后将数据转给目标节点的VTEP设备，最后根据路由表转发至cni0，然后抵达目标容器。
### (4) 对外接口Ingress
我们先前提到的网络技术都是为了Kubernetes集群内互相访问而设计的，集群外部是无法通过集群内部的VIP去访问Service，也无法通过私有地址去访问Pod，为了将Service开放给集群外部使用，Kubernetes设计了Ingress这个组件。

Ingress实际上是Kubernetes对反向代理的抽象，因此可以给Ingress配置提供外部可访问的URL、负载均衡、SSL、基于名称的虚拟主机等。用户通过 POST Ingress 资源到 API server 的方式来请求 ingress。Ingress controller负责实现Ingress，通常使用负载均衡器，它还可以配置边界路由和其他前端，这有助于以高可用的方式处理流量。
## 4. 服务网格与Istio
### (1) 微服务与服务网格
很长一段时间，传统的软件应用程序一般都是作为单个项目开发，其使用单一编程语言，具有单一的代码库和单个可执行文件，这种开发模式对于小型项目还好说，对于一个具有多个模块的大型项目就是灾难了，由于大部分代码紧密耦合，某一处代码的微小变化都可能导致整体应用的改变，因此测试项目时可能需要多个项目组联调，就更不要说引入其他编程语言的特性了。

在以Docker和Kubernetes为代表的容器及其编排技术出现后，由于不同容器之间的运行环境隔离，这种情况得到了很大改善，应用的不同部分可以拆分开作为几个小型项目单独开发，项目与项目之间采用轻量级通信技术进行沟通，每个服务都围绕具体的业务进行构建，一个项目的更改不会影响其他项目的正常运行，这也即是**微服务**架构。

微服务架构虽然具有模块间松耦合，多种编程语言配合的优点，但也带来了一些新的问题。首先，我们可以发现微服务架构事实上将多个模块之间通过内存的通信改为了经由本地网络进行的通信，不同的模块可能会使用不同的编程语言，而不同语言对通信协议的支持是不同的，想要跨语言调用就需要选择合适的通信协议及序列化技术，这对由两个以上编程语言开发的项目是极其难以处理的。其次，由新语言开发的微服务，无法使用先前累计的服务治理的策略，比如负载均衡、熔断降级、流量控制、分布式追踪日志等，这些治理策略都需要由新语言重新实现一遍，这对一个小模块是不可接受的。因此开发者希望能够继续解耦合，将服务治理策略与具体的业务分离，形成一个代理层单独部署，这个代理层使用单一的语言实现，所有流量都经过代理层，集中使用其中的治理策略，这也是**服务网格Service Mesh**的核心思想。

总而言之，服务网格实际上是微服务之间的一个通信协议，进出服务的流量经代理层实现统一调配的服务发现、负载均衡、服务路由、流量控制之后，再进入微服务或者发往其他微服务。这种方式将服务治理策略和业务代码分离，成为独立的模块，从而实现跨语言服务治理策略的复用和统一管理。


### (2) Istio和Sidecar模式

目前业界提及最多的服务网格实现方案是Istio，其是由谷歌、IBM与Lyft共同开发的开源项目，旨在提供统一的微服务连接、安全保障、管理与监控方式。
Istio一般与Kubernetes搭配使用，在Kubernetes中，每一个微服务被部署为一个Pod运行。先前的介绍中我们提到在同一个Pod中的容器共享一个网络命名空间，拥有自己独立的网络栈。Istio将一个包含代理程序的特殊容器植入到自己所管理的每一个Pod之中，通过修改iptables规则劫持进出站流量，从而实现对Pod的反向代理，劫持的过程对Pod来说是透明的，每一个Pod都部署一个代理容器的模式也被称为Sidecar(边车)模式。由于微服务之间的通信都由Sidecar代理，服务治理策略只需要部署在Sidecar上即可，通过Sidecar统一调整所有Pod的网络命名空间的策略，即可实现对服务治理策略的复用。

### (3) Istio架构

Istio从逻辑上分为数据平面和控制平面，数据平面由一组代理组成，在Kubernetes集群中被部署为sidecar容器存在，协调和控制所有服务之间的网络通信。控制平面负责管理和配置代理路由流量，以及在运行时执行的政策。微服务之间的通信在sidecar容器之间直接进行而不经过控制平面，控制平面除了下发代理的配置还负责收集一些数据信息，这些信息会被集成到一个仪表盘展示给运维人员。

Istio默认使用的代理容器是Envoy代理的扩展版本，该代理是以 C++ 开发的高性能代理，用于调解服务网格中所有服务的所有入站和出站流量。Envoy 代理被部署为服务的 sidecar，在逻辑上为服务增加了 Envoy 的许多内置特性，例如：动态服务发现、负载均衡、TLS 终端、HTTP/2 与 gRPC 代理、熔断器、健康检查、基于百分比流量分割的分阶段发布、故障注入等服务。

Envoy对流量的劫持仍然是基于iptables实现的，启用istio后，在Infra的网络命名空间中使用命令iptables -L -v即可查看sidecar注入的规则，sidecar流量劫持示意图如图XX所示。
### (4) 数据可视化

## 5. ipv6背景下广域多集群服务互联技术
### (1) ipv6对Kubernetes集群的影响
先前我们提到，Kubernetes中Pod的IP是扁平化的，也即集群内所有Pod的IP不重复，并且可以直接通信
### (2) srv6和
### (3) srv6技术对服务网格的优化（？影响？）
