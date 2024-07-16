# Docker和Kubernetes网络模型
## 1. Docker网络模型
https://www.cnblogs.com/bakari/p/10613710.html
### (1) Linux网络虚拟化
我们知道，运行于**Linux**上的Docker所实现的容器本身并不是像虚拟机一样，讲Host和VM通过hypervisor完全隔离开来，而是通过namespace技术限制了进程能“看到”的资源，例如进程的PID，工作目录以及网络接口；然后通过Cgroups限制单个容器所能占用的资源；最后通过分层镜像系统完成整个容器的构建。所以容器本身仍然是运行在OS上的一个特殊的进程，所有的容器共用一个Linux内核。在网络这一部分，桥接模式下容器之间的网络隔离则主要依赖于网络命名空间network namespace，虚拟网络设备veth-pair以及网桥（虚拟交换机）来实现，因此在介绍Docker网络之前有必要先了解Linux网络虚拟化技术。
#### a. Network namespace
在Linux使用命令ip netns add _____即可创建一个新的netns，创建之后系统会在/var/run/netns下生成一个挂载点存储该netns。每个netns拥有自己独立的网络栈，也即网卡，回环设备，路由表和iptables防火墙规则，一般来说我们希望不同的容器有不同的netns，从而避免复杂的网络配置。
#### b. 网桥和veth-pair
容器被隔离在自己独立的netns中，和外部的连接以及容器间的通信就成了问题，在Linux中能起到虚拟交换机功能的是网桥，其主要功能是根据MAC地址将数据包转发到不同的端口上。
对于不同的netns，我们可以通过创建一个虚拟网络设备veth-pair进行连接，使用命令ip link add type veth创建一对网络接口，使用命令ip link set veth0 netns net0将一个接口分配给某个netns，分别将两个接口接到不同的netns之后，这两个netns之间就可以进行通信了，但是

### (2) 桥接模式
### (3) Host模型
### (4) 无网络模式
## 2. Kubernetes网络模型
### 
