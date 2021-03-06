# K题题解

## 1.题意

一个长度为$n$的环，一个人从起点往前走，第$i$次走$i$格，问几次后回到起点

## 2.题解

由等差数列求和公式，我们可以得到第$x$次前进的长度为$\frac{x(x+1)}{2}$

那么要求解的式子就可以表示为$\frac{x(x+1)}{2}\equiv0 \ mod\ n $

也即$x(x+1)=2kn$

注意到$x$和$x+1$互质，因此我们可以尝试对$2n$进行质因数分解

分解完成后将一部分质因数放入$x+1$另一部分放入$x$，设放入$x+1$的为$d$，则放入$x$的为$\frac{2n}{d}$

另外还注意到$x+1-x=1$，设$k=ab$，则$x+1-x=1$可以化为$ad-b\frac{2n}{d}=1$，这就变成了一个二元一次方程求正整数解的问题，我们需要$x$够小，也即$k$够小，因此枚举$d$放入$x+1$，每次枚举都求解$ad-b\frac{2n}{d}$，维护$ab=k$的最小值即可

需要注意$\sqrt{n}$的判断质数算法会超时，需要用更高效的判断质数算法

