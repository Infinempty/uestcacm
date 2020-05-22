#include<bits/stdc++.h>
#define ll long long

const ll MOD=1000000007;
ll dp[1005][11][11];
using namespace std; 
string a[3];
ll dfs(int pos,
		bool lead,
		int pre1,int pre2,
		int t,
		bool limit,int len)
	{	
	if(pos==len)return 1;
	if(!lead&&!limit&&pre2!=-1&&dp[pos][pre1][pre2]!=-1)return dp[pos][pre1][pre2];
	ll ans=0;
	int up=limit?(ll)(a[t][pos]-'0'):9;
	for(int i=0;i<=up;i++){
		if(pre1==i&&!lead)continue;
		else if(pre2==i&&!lead)continue;
		ans=(ans+dfs(pos+1,lead&&i==0,lead&&i==0?-1:i,pre1,t,limit&&i==up,len)%MOD)%MOD;
	}
	if(!lead&&!limit&&pre2!=-1)dp[pos][pre1][pre2]=ans;
	return ans;
}
bool judge(int len2){
	for(int i=1;i<len2;i++){
		if(a[2][i]==a[2][i-1]||(i>1&&a[2][i]==a[2][i-2])){
			return 0;
		}
	}
	return 1;
}
void solve(){
	memset(dp,-1,sizeof(dp));
	cin>>a[2]>>a[1];
	int len1=a[1].size(),len2=a[2].size();
	ll sum1=0,sum2=0;
	ll tmp1=dfs(0,1,-1,-1,1,1,len1);
	memset(dp,-1,sizeof(dp));
	ll tmp2=dfs(0,1,-1,-1,2,1,len2);
	if(judge(len2))tmp2--;
	ll ans=(tmp1-tmp2+MOD)%MOD;
	for(int i=0;i<len1;i++){
		sum1=((sum1*10)%MOD+(ll)(a[1][i]-'0'))%MOD;
	}
	for(int i=0;i<len2;i++){
		sum2=((sum2*10)%MOD+(ll)(a[2][i]-'0'))%MOD;
	}
	ans=((sum1-sum2+1+MOD)%MOD-ans+MOD)%MOD;
	printf("%lld",ans);
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
