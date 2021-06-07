//https://www.luogu.com.cn/problem/P4717
#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
const int maxn=(1<<17)+5,mod=998244353;
int n,len=1<<17,A[maxn],B[maxn],C[maxn];
inline int ad(int u,int v)
{
    return (u+=v)>=mod ? u-mod : u;
}
inline int div2(int x)
{
    return x&1 ? (mod+x)/2 : x/2;
}
void FMT(int *a)
{
    for(int z=1;z<len;z<<=1) for(int j=0;j<=len-1;j++) if(z&j) a[j]=ad(a[j],a[j^z]);
    return;
}
void IFMT(int *a)
{
    for(int z=1;z<len;z<<=1) for(int j=0;j<=len-1;j++) if(z&j) a[j]=ad(a[j],mod-a[j^z]);
    return;
}
void FWT_and(int *a)
{
    for(int i=2,ii=1;i<=len;i<<=1,ii<<=1) for(int j=0;j<len;j+=i) for(int k=0;k<ii;++k) a[j+k]=ad(a[j+k],a[j+k+ii]);
    return;
}
void IFWT_and(int *a)
{
    for(int i=2,ii=1;i<=len;i<<=1,ii<<=1) for(int j=0;j<len;j+=i) for(int k=0;k<ii;++k) a[j+k]=ad(a[j+k],mod-a[j+k+ii]);
    return;
}
void FWT_xor(int *a)
{
    int t;
    for(int i=2,ii=1;i<=len;i<<=1,ii<<=1){
        for(int j=0;j<len;j+=i){
            for(int k=0;k<ii;++k){
                t=a[j+k];
                a[j+k]=ad(t,a[j+k+ii]);
                a[j+k+ii]=ad(t,mod-a[j+k+ii]);
            }
        }
    }
    return;
}
void IFWT_xor(int *a)
{
    int t;
    for(int i=2,ii=1;i<=len;i<<=1,ii<<=1){
        for(int j=0;j<len;j+=i){
            for(int k=0;k<ii;++k){
                t=a[j+k];
                a[j+k]=div2(ad(t,a[j+k+ii]));
                a[j+k+ii]=div2(ad(t,mod-a[j+k+ii]));
            }
        }
    }
    return;
}
int main()
{
    n=read();
    len=1<<n;
    for(int i=0;i<=len-1;i++) A[i]=read();
    for(int i=0;i<=len-1;i++) B[i]=read();
    FMT(A);
    FMT(B);
    for(int i=0;i<=len-1;i++) C[i]=(ull)A[i]*B[i]%mod;
    IFMT(A);
    IFMT(B);
    IFMT(C);
    for(int i=0;i<=len-1;i++) printf("%d ",C[i]);
    printf("\n");
    FWT_and(A);
    FWT_and(B);
    for(int i=0;i<=len-1;i++) C[i]=(ull)A[i]*B[i]%mod;
    IFWT_and(A);
    IFWT_and(B);
    IFWT_and(C);
    for(int i=0;i<=len-1;i++) printf("%d ",C[i]);
    printf("\n");
    FWT_xor(A);
    FWT_xor(B);
    for(int i=0;i<=len-1;i++) C[i]=(ull)A[i]*B[i]%mod;
    IFWT_xor(C);
    for(int i=0;i<=len-1;i++) printf("%d ",C[i]);
    printf("\n");
    return 0;
}
