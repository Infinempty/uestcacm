#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=0x3f3f3f3f;
vector<int> v[205];
vector<int> s[205];
int dp[205][205],vis[205];
int n,p;
void dfs(int r){
	for(int i=0;i<v[r].size();i++){
		dfs(v[r][i]);
		for(int j=p;j>1;j--){
			for(int k=1;k<j;k++)
				dp[r][j]=min(dp[r][j],dp[r][j-k]+dp[v[r][i]][k]-2);
		}
	}
}
void search(int r){
	vis[r]=1;
	for(int i=0;i<s[r].size();i++){
		if(vis[s[r][i]])continue;
		v[r].push_back(s[r][i]);
		search(s[r][i]);
	}
}
void solve(){
	int a,b,ans=INF;
	scanf("%d %d",&n,&p);
	for(int i=1;i<n;i++){
		scanf("%d %d",&a,&b);
		s[a].push_back(b);
		s[b].push_back(a);
	}
	search(1);
	for(int i=1;i<=n;i++){
		dp[i][1]=v[i].size()+1;
		for(int j=2;j<=p;j++)
			dp[i][j]=INF;
	}
	dfs(1);
	ans=dp[1][p]-1;
	for(int i=1;i<=n;i++)
		ans=min(ans,dp[i][p]);
	printf("%d",ans);
	
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
