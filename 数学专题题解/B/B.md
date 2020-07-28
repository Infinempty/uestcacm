# B题题解

## 1.题意：

求解：$\sum_{i=1}^n\mu(gcd(i,n))gcd(i,n)$

## 2.题解：

先来考虑最大公因数和欧拉函数的关系

$\varphi(n)=\sum_{i=1}^n[gcd(i,n)=1]$

我们希望原函数能和欧拉函数扯上一定的关系以方便推导

考虑$\sum_{i=1}^n[gcd(i,n)=d]$

当$d=1$时，上式转换为$\varphi(n)$

当$d\neq1$时，我们可以两边除以$d$将原式化为$\sum_{i=1}^{\frac{n}{d}}[gcd(i,\frac{n}{d}=1])=\varphi(\frac{n}{d})$

也就是说，对于从1到n中最大公因数相同且为d的数量是$\varphi(\frac{n}{d})$个，现在就比较好做了

原式可以按照$n$的因数分为$d(n),d(n)$为n的因数组，每一组的值可以表示为$d\mu(d)\varphi(\frac{n}{d})$

原式$=\sum_{d\mid n}d\mu(d)\varphi(\frac{n}{d})$，设$g=d\mu(d)$，则原式=$g*\varphi$，又由$\varphi=\mu*id$

原式=$g*\mu*id=g*id*\mu,g*id=\sum_{d\mid n}d\mu(d)\frac{n}{d}=n\sum_{d\mid n}\mu d(d)=n\varepsilon(n)=\varepsilon(n)$(n只有等于1时不为0，因此可以换成这个式子)

那么原式=$\varepsilon*\mu=\mu$，故原式$=\mu(n)$，利用$\mu(n)$定义在$\sqrt n$时间内求出即可





