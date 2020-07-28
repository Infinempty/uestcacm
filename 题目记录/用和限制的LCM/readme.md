今天遇到了一个比较经典的问题

求解方程：

$x+y=a\\lcm(x,y)=b\\x,y\in Z^+$

显而易见的存在一个暴力算法，我们从2遍历到a，算法复杂度$O(aloga)$

当数据规模较大时枚举不能有效解决问题，需要寻找更优秀的解法

1.首先证明引理$gcd(a,b)=gcd(x,y)$

不妨假设$gcd(x,y)=k$

则$x=ki,y=kj$其中$gcd(i,j)=1$

则有$k(i+j)=a\\kij=b$

假设$gcd(i+j,ij)=k_1\neq1$

则$i+j=k_1(x_1+x_2)$这意味着$i$与$j$存在不为1的最大公因数$k_1$，与$gcd(i,j)=1$矛盾

故$i+j$与$ij$互质

故$a$与$b$的最大公因数即为$k$，因为从$a,b$中拿出$k$后剩余部分互质

$gcd(x,y)=gcd(a,b)$得证

2.由引理1，我们所求解的方程可以变形为

$x+y=a\\xy=bgcd(a,b)$

原问题就变成解二次方程$x^2-ax+bgcd(a,b)=0$

解得$x=\frac{a+\sqrt{a^2-4bgcd(a,b)}}{2},y=\frac{a-\sqrt{a^2-4bgcd(a,b)}}{2}$

无解条件很显然有3个

$\Delta=a^2-4bgcd(a,b)<0$

$\sqrt{\Delta}\notin Z$

$a\pm\sqrt\Delta \equiv1\ mod\ 2$

写代码过程中我们可以简单的用运算后的$x,y$相乘验证其是否等于$bgcd(a,b)$

本题到此就结束了

3.衍生问题

这个问题有个衍生问题

$x+y=a\\gcd(x,y)=b$

上式可以变形为

$b(i+j)=a,gcd(a,b)=b$

故无解条件为$a\%b\neq 0$

否则可取$x=b,y=a-b$





