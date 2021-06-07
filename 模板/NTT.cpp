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
const ll MOD=998244353;
const int MAXN=3000050;
const double pi=acos(-1.0);
int lim=1;

int idx[MAXN];
ll a[MAXN],b[MAXN],ans[MAXN];

ll mpow(ll a,ll n){
	ll ans=1;
	while(n){
		if(n&1){
			ans*=a;
			ans%=MOD;
		}
		a*=a;
		a%=MOD;
		n>>=1;
	}
	return ans;
}
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
void ntt(ll A[],int type){
	const ll G=3,Gi=332748118;
	for(int i=0;i<lim;i++){
		if(i<idx[i])swap(A[i],A[idx[i]]);
	}
	for(int mid=1;mid<lim;mid<<=1){
		ll Wn=mpow(type==1?G:Gi,(MOD-1)/(mid<<1));
		int r=mid<<1;
		for(int j=0;j<lim;j+=r){
			ll w=1;
			for(int k=0;k<mid;k++,w=(w*Wn)%MOD){
				ll x=A[j+k],y=w*A[j+mid+k]%MOD;
				A[j+k]=x+y;
				A[j+k]%=MOD;
				A[j+mid+k]=x-y+MOD;
				A[j+mid+k]%=MOD;
			}
		}
	}
}
void poly_multiply(int n,int m){
	//n是多项式A的次数，m是B的
	butterfly(n+m);
	ntt(a,1);
	ntt(b,1);
	for(int i=0;i<lim;i++){
		a[i]=a[i]*b[i];
		a[i]%=MOD;
	}
	ntt(a,-1);
	//a[i]的实部除以lim才是答案
	ll inv=mpow(lim,MOD-2);
	for(int i=0;i<=n+m;i++){
		ans[i]=a[i]*inv;
		ans[i]%=MOD;
	}
}

void solve(int T){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=0;i<=m;i++)scanf("%lld",&b[i]);
	poly_multiply(n,m);
	for(int i=0;i<=n+m;i++){
		printf("%lld ",ans[i]);
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