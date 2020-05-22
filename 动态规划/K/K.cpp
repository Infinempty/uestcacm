#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum[22][22],cnt[22],a[100050];
ll dp[1100000];
ll n,m=0;
ll get_sum(ll sta,ll t){
	ll tmp=0;
	for(ll i=0;i<20;i++){
		if(!(sta&(1<<i)))continue;
		tmp+=sum[t+1][i+1];
	}
	return tmp;
}
ll dfs(ll sta,ll x){
	if(x==0)return 0;
	if(dp[sta]!=-1)return dp[sta];
	ll ans=1e12,nex_sta=0;
	
	for(ll i=0;i<20;i++){
		if(!(sta&(1<<i)))continue;
		nex_sta=sta-(1<<i);
		ans=min(ans,dfs(nex_sta,x-1)+get_sum(nex_sta,i));
	}
	dp[sta]=ans;
	return ans;
}
void solve(){
	ll sta=0;
	memset(dp,-1,sizeof(dp));
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		cnt[a[i]]++;
	}
	for(ll i=1;i<=20;i++){
		if(cnt[i]){
			sta=sta|(1<<(i-1));
			m++;
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=20;j++){
			if(a[i]==j)continue;
			sum[a[i]][j]+=cnt[j];
		}
		cnt[a[i]]--;
	}
	
	printf("%lld",dfs(sta,m));
	
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
