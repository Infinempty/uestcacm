#include<bits/stdc++.h>
#define ll long long
using namespace std;
int sum[22][100050],cnt[22];
int dp[1100000],f[1100000];
int n,m;
int dfs(int sta,int x,int end){
	if(x==0)return 0;
	if(dp[sta]!=-1)return dp[sta];
	int ans=0,nex_sta=0;
	int nex_end=0;
	for(int i=0;i<m;i++){
		if(!(sta&(1<<i)))continue;
		nex_sta=sta-(1<<i);
		nex_end=end-cnt[i+1];
		ans=max(ans,dfs(nex_sta,x-1,nex_end)+sum[i+1][end]-sum[i+1][nex_end]);
	}
	dp[sta]=ans;
	return ans;
}

void solve(){
	int tmp;
	memset(dp,-1,sizeof(dp));
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		//cnt[tmp][n]¼´¼ÆÊı 
		for(int j=1;j<=m;j++){
			if(tmp==j)sum[j][i]=sum[j][i-1]+1; 
			else sum[j][i]=sum[j][i-1];
		}
		cnt[tmp]++;
	}
	int sta=(1<<m)-1;
	printf("%d",dfs(sta,m,n));
	
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
