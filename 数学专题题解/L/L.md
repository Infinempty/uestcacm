# L题题解

## 1.题意：

求满足$a^x\equiv b\ mod \ m,x$的最小值

## 2.题解：

1.BSGS：

当a与m互质时时，本题退化为一般的BSGS，先看一般BSGS如何求

根据拓展欧拉定理$a^x\equiv a^{x\ mod\ \phi(m)}\ mod\ m$，我们可以发现$a^0-a^{m-1}$是一个循环节，

暴力求解只需遍历，复杂度$O(m)$，显然这么做会超时，运用分块思想，我们设$t=ceil(\sqrt{m})$，

$x$可以表示为$x=nt-k,k\in[0,t-1]$，则原式变为$a^{nt-k}\equiv b\ mod\ m$，即$a^{bt}\equiv ba^k\ mod \ m$

由于$k\in[0,t-1]$我们只需要求出$a^k\ mod\ m$的值然后用hash表记录其次数，然后对于$a^{bt}mod\ m$每个数值都查询这个值在哈希表是否存在，若存在则输出$bt-hash[a^{bt}]$

2.拓展BSGS

当a与m不互质时，事实上我们可以不断除以他们的最大公因数使他们变得互质，这样扩展BSGS就变成了一般BSGS问题了，

具体情况我们可以先求得一个最大公因数$d_1=gcd(a,m)$，然后$a^x\equiv b\ mod \ m$两边除以$d_1$可得

$\frac{a}{d_1}a^{x-1}\equiv \frac{b}{d_1}\ mod\ \frac{p}{d1}$，这样子不断处理下去，假设$D=\prod_{i=1}^pd_k$，原方程变为$\frac{a^k}{D}a^{x-k}\equiv \frac{b}{D}\ mod\ \frac{m}{D}$

这样就可以将方程化为$a^{x-k}\equiv \frac{b}{D}inv(\frac{a}{D})\ mod\ \frac{m}{D}$，此时a与m互质，可以套入BSGS中求解

有个问题，如果b无法整除d该怎么办？这个时候$a$在模$p$意义下无逆元，原方程无解