#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[40050],que[40050],num[40050];
inline ll max(ll x,ll y){return x>y?x:y;}
inline ll min(ll x,ll y){return x<y?x:y;}
void solve(){
	ll n,C,l,r,t,a,b,c,y,len,sz,v,w,m;
	scanf("%lld %lld %lld",&n,&t,&C);
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld %lld",&w,&v,&m);
		len=min(C/w,m);//窗口长度  滑动窗口模型 
		for(ll j=0;j<w;j++){
			l=1,r=1;
			sz=(C-j)/w;//数据长度 
			for(ll k=0;k<=sz;k++){
				y=dp[j+k*w]-k*v;
				while(l<r&&num[l]+len<k)l++;
				while(l<r&&que[r-1]<y)r--;
				que[r]=y;
				num[r]=k;
				r++;
				dp[j+k*w]=max(dp[j+k*w],que[l]+k*v);
			}
		}
	}
	for(ll i=1;i<=t;i++){
		scanf("%lld %lld %lld",&a,&b,&c);
		for(ll j=C;j>=0;j--){
			for(ll k=0;k<=j;k++){
				dp[j]=max(dp[j],dp[j-k]+k*(a*k+b)+c);
			}
		}
	}
	printf("%lld",dp[C]);
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t=1;
	//scanf("%d",&t);
	while(t--){
		solve();
	}
}
