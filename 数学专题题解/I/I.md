# I题题解

## 1.题意

求$\sum_{i=l}^r\sum_{j=1}^if(i,j),f(i,j)$表示$\frac{i}{j}$的小数部分

## 2.题解

$\sum_{i=l}^r\sum_{j=1}^if(i,j)=\sum_{i=l}^r\sum_{j=1}^i(\frac{i}{j}-\lfloor\frac{i}{j}\rfloor)$

$=\sum_{i=l}^r\sum_{j=1}^i\frac{i}{j}-\sum_{i=l}^r\sum_{j=1}^i\lfloor\frac{i}{j}\rfloor$

1.对于$\sum_{i=l}^r\sum_{j=1}^i\frac{i}{j}=\sum_{i=l}^ri\sum_{j=1}^i\frac{1}{j}$，

在模m意义下，上式$=\sum_{i=l}^ri\sum_{j=1}^iinv(j)$，其中$inv(j)$表示j在模m意义下的逆元

2.对于$\sum_{i=l}^r\sum_{j=1}^i\lfloor\frac{i}{j}\rfloor$，考虑$\lfloor\frac{i}{j}\rfloor$，这个式子和$[1,i]$区间内能整除$j$的数个数相同

因此原式变为$\sum_{i=l}^r\sum_{j=1}^i\sum_{k=1}^i[j\mid k]$，双重求和符号可交换次序

原式$=\sum_{i=l}^r\sum_{k=1}^i\sum_{j=1}^i[j\mid k]=\sum_{i=l}^r\sum_{k=1}^id(k),d(k)$为k的因子数目

因此我们需要维护$inv(j)$的前缀和，记为$sum_1(i)$，$isum_1(i)$的前缀和，记为$sum_2(i)$

$d(k)$的前缀和，记为$sum_3(i)$，$sum_3(i)$的前缀和，记为$sum_4(i)$

最终答案$ans=sum_2(r)-sum_2(l-1)+sum_4(r)-sum_4(l-1)$

3.$d(k)$的求解，假设k的质因数分解为$k=p_1^{a_1}p_2^{a_2}\cdots p_n^{a_n}$，则$d(k)=\prod_{i=1}^n(a_i+1)$

设$div[i]$是$i$的最小质因数的次数，在筛选过程中，设$p$是当前筛选所用质数，

若$p\mid i$，则$d[ip]=\frac{num[i]\times(div[i]+2)}{div[i]+1},div[ip]=div[i]+1$，相当于把最小质数的次数升高了一次

否则$d[ip]=d[i]d[p],div[ip]=1$，两数互质，任取因子都是$ip$的因数

在欧拉筛的过程中便求出了所有数的因数个数



