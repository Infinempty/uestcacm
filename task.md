# 云原生网络模型简介
https://www.cnblogs.com/bakari/p/10613710.html
## 1. Linux网络虚拟化
我们知道，运行于**Linux**上的Docker所实现的容器本身并不是像虚拟机一样，讲Host和VM通过hypervisor完全隔离开来，而是通过namespace技术限制了进程能“看到”的资源，例如进程的PID，工作目录以及网络接口；然后通过Cgroups限制单个容器所能占用的资源；最后通过分层镜像系统完成整个容器的构建。所以容器本身仍然是运行在OS上的一个**特殊的进程**，所有的容器共用一个Linux内核。在网络这一部分，桥接模式下容器之间的网络隔离则主要依赖于网络命名空间network namespace，虚拟网络设备veth-pair以及网桥（虚拟交换机）来实现，多节点容器交互则利用了Linux内核的netfilter，因此在介绍Docker网络之前有必要先了解Linux网络技术。
### (1) Network namespace
在Linux使用命令ip netns add XXX即可创建一个新的netns，创建之后系统会在/var/run/netns下生成一个挂载点存储该netns。每个netns拥有自己独立的网络栈，也即网卡，回环设备，路由表和iptables防火墙规则，一般来说我们希望不同的容器有不同的netns，从而避免复杂的网络配置。
### (2) 网桥和veth-pair
容器被隔离在自己独立的netns中，和外部的连接以及容器间的通信就成了问题，在Linux中能起到虚拟交换机功能的是网桥，其主要功能是根据MAC地址将数据包转发到不同的端口上。
对于不同的netns，我们可以通过创建一个虚拟网络设备veth-pair进行连接，使用命令ip link add type veth创建一对网络接口，使用命令ip link set veth0 netns net0将一个接口分配给某个netns，分别将两个接口接到不同的netns之后，这两个netns之间就可以进行通信了，但是这样只能使得直接连接的两个netns进行通信，如果netns较多，这样的通信就会很麻烦。
现实中解决多机互联问题一般会引入一台交换机进行2层路由，在Linux中则以网桥作为虚拟交换机，利用指令ip link add br0 type bridge即可创建一个网桥，然后利用命令ip link set br-veth0 master br0，即可将veth-pair的一端连接到网桥，另一端用命令ip link set veth0 netns ns1就可以接入netns，这样所有接入网桥的容器即可互相通信。
### (3) netfilter和iptables
Netfilter是Linux内核中的一个软件框架，用于管理网络数据包。不仅具有网络地址转换（NAT）的功能，也具备数据包内容修改、以及数据包过滤等防火墙功能，iptables是其在用户侧的接口的一种实现，iptables主要包括“四表五链”，分别是filter表，nat表，mangle表，raw表；五链分别是PREROUTING，POSTROUTING，FORWOAD，INPUT，OUTPUT。外网进入计算机的数据都会经这五链进行转发，主要关系如图1所示（加图），四表则对其制定规则，数据包过滤，数据包转发，地址转换（NAT）等功能。使用命令iptables -L -n -t tables_name即可查看不同表中的规则。
## 2. Docker网络模型
### (1) 桥接与Container模式
### (2) Host模式
### (3) 无网络模式
## 3. Kubernetes网络模型
### (1) cni网桥和Pod网络
### (2) kube-proxy和service
### (3) 多节点互联Flannel
### (4) 对外接口Ingress
## 4. 服务网格与Istio
### (1) 服务网格概念
### (2) Envoy代理组件
### (3) Sidecar模式流量劫持
### (4) 流量控制、安全管理与开发调试
### (5) 数据可视化
## 5. ipv6背景下广域多集群服务互联技术
### (1) ipv6对数据网格的影响
### (2) 异地服务调用对istio功能的影响
### (3) srv6技术对服务网格的优化（？影响？）
