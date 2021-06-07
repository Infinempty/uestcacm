#include<bits/stdc++.h>

#define all(x) x.begin(),x.end()
#define pb push_back
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int INF=0x3f3f3f3f;
const ll LINF=1e18;
const ll MOD=1e9+7;
const int MAXN=3000050;
const double pi=acos(-1.0);
int lim=1;

int idx[MAXN],ans[MAXN];
struct cpx{
	double x,y;
	cpx(double xx=0,double yy=0){
		x=xx;
		y=yy;
	}
}a[MAXN],b[MAXN];
cpx operator + (cpx a,cpx b){return cpx(a.x+b.x,a.y+b.y);}
cpx operator - (cpx a,cpx b){return cpx(a.x-b.x,a.y-b.y);}
cpx operator * (cpx a,cpx b){return cpx(a.x*b.x-a.y*b.y , a.x*b.y+a.y*b.x);}

char in1[MAXN],in2[MAXN];
void butterfly(int n){
	//n是乘积后多项式次数
	int l=0;
	while(lim<=n){
		lim<<=1;
		l++;
	}
	for(int i=0;i<lim;i++){
		idx[i]=(idx[i>>1]>>1)|((i&1)<<(l-1));
	}
}
void fft(cpx A[],int type){
	for(int i=0;i<lim;i++){
		if(i<idx[i])swap(A[i],A[idx[i]]);
	}
	for(int mid=1;mid<lim;mid<<=1){
		cpx Wn(cos(pi/mid),type*sin(pi/mid));
		int r=mid<<1;
		for(int j=0;j<lim;j+=r){
			cpx w(1,0);
			for(int k=0;k<mid;k++,w=w*Wn){
				cpx x=A[j+k],y=w*A[j+mid+k];
				A[j+k]=x+y;
				A[j+mid+k]=x-y;
				
			}
		}
	}
}
void poly_multiply(int n,int m){
	//n是多项式A的次数，m是B的
	butterfly(n+m);
	fft(a,1);
	fft(b,1);
	for(int i=0;i<=lim;i++){
		a[i]=a[i]*b[i];
	}
	fft(a,-1);
	//a[i]的实部除以lim才是答案
	for(int i=0;i<=n+m;i++){
		ans[i]=(int)(a[i].x/lim+0.5);
	}
}

void solve(int T){
	int n,m;
	scanf("%s",in1);
	scanf("%s",in2);
	n=strlen(in1),m=strlen(in2);
	reverse(in1,in1+n);
	reverse(in2,in2+m);
	for(int i=0;i<n;i++){
		a[i].x=double(in1[i]-'0');
	}
	for(int i=0;i<m;i++){
		b[i].x=double(in2[i]-'0');
	}
	poly_multiply(n,m);
	for(int i=0;i<=n+m;i++){
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	int top=n+m;
	for(int i=n+m;i>=0;i--){
		if(ans[i]!=0){
			top=i;
			break;
		}
	}
	for(int i=top;i>=0;i--){
		printf("%d",ans[i]);
	}
	
}

signed main()
{
	//IOS;
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
    	solve(i);
	}
}