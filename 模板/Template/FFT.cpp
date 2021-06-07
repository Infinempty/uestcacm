//www.luogu.org/problem/P3803
#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define maxn 2500010
using namespace std;
//using namespace __gnu_pbds;
const double PI=acos(-1.0);
const double eps=1e-6;
int n,limit=1,m,l,r[maxn];
struct Complex
{
    double x,y;
    Complex(double _x=0,double _y=0)
    {
        x=_x;
        y=_y;
    }
}a[maxn],b[maxn];
Complex operator +(Complex a,Complex b)
{
    return Complex(a.x+b.x,a.y+b.y);
}
Complex operator -(Complex a,Complex b)
{
    return Complex(a.x-b.x ,a.y-b.y);
}
Complex operator *(Complex a,Complex b)
{
    return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
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
void FFT(Complex A[],int type)
{
    for(int i=0;i<limit;i++) if(i<r[i]) swap(A[i],A[r[i]]);
    for(int mid=1;mid<limit;mid<<=1){
        Complex wn(cos(PI/mid),type*sin(PI/mid));
        for(int R=mid<<1,j=0;j<limit;j+=R){
            Complex w(1,0);
            for(int k=0;k<mid;k++,w=w*wn){
                Complex x=A[j+k],y=w*A[j+mid+k];
                A[j+k]=x+y;
                A[j+mid+k]=x-y;
            }
        }
    }
    return;
}
int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n=read(),m=read();
    for(int i=0;i<=n;i++) a[i].x=read();
    for(int i=0;i<=m;i++) b[i].x=read();
    while(limit<=n+m) limit<<=1,l++;
    for(int i=0;i<limit;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    FFT(a,1);
    FFT(b,1);
    for(int i=0;i<=limit;i++) a[i]=a[i]*b[i];
    FFT(a,-1);
    for(int i=0;i<=n+m;i++) printf("%d ",(int)(a[i].x/limit+0.5));
	return 0;
}
//大数乘法
#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define maxn 200100
using namespace std;
//using namespace __gnu_pbds;
const double PI=acos(-1.0);
const double eps=1e-6;
char sa[maxn],sb[maxn];
int n,limit=1,l,r[maxn];
int ans[maxn];
struct Complex
{
    double x,y;
    Complex(double _x=0,double _y=0)
    {
        x=_x;
        y=_y;
    }
}a[maxn],b[maxn];
Complex operator +(Complex a,Complex b)
{
    return Complex(a.x+b.x,a.y+b.y);
}
Complex operator -(Complex a,Complex b)
{
    return Complex(a.x-b.x ,a.y-b.y);
}
Complex operator *(Complex a,Complex b)
{
    return Complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
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
void FFT(Complex A[],int type)
{
    for(int i=0;i<limit;i++) if(i<r[i]) swap(A[i],A[r[i]]);
    for(int mid=1;mid<limit;mid<<=1){
        Complex wn(cos(PI/mid),type*sin(PI/mid));
        for(int R=mid<<1,j=0;j<limit;j+=R){
            Complex w(1,0);
            for(int k=0;k<mid;k++,w=w*wn){
                Complex x=A[j+k],y=w*A[j+mid+k];
                A[j+k]=x+y;
                A[j+mid+k]=x-y;
            }
        }
    }
    return;
}
int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n=read();
    scanf("%s",sa);
    scanf("%s",sb);
    int aa=0,bb=0;
    for(int i=n-1;i>=0;i--) a[aa++].x=sa[i]-'0';
    for(int i=n-1;i>=0;i--) b[bb++].x=sb[i]-'0';
    while(limit<=n+n) limit<<=1,l++;
    for(int i=0;i<limit;i++) r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    FFT(a,1);
    FFT(b,1);
    for(int i=0;i<=limit;i++) a[i]=a[i]*b[i];
    FFT(a,-1);
    for(int i=0;i<=limit;i++){
        ans[i]+=(int)(a[i].x/limit+0.5);
        if(ans[i]>=10) ans[i+1]+=ans[i]/10,ans[i]%=10,limit+=(i==limit);
    }
    while(!ans[limit] && limit>=1) limit--;
    limit++;
    while(--limit>=0) cout<<ans[limit];
	return 0;
}
