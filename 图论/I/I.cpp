#include<bits/stdc++.h>
#define ll long long
#define MAX 1e18
using namespace std;
vector<int> v[100050];
bool is_cut[100050];
int pre[100050],low[100050],vis[100050];
int n,m,dfs_clock=1,ans=0;
int dfs(int now,int fa){
	int lown=0,nxt=0,low_nxt=0,child=0;
	lown=pre[now]=dfs_clock++;
	for(int i=0;i<v[now].size();i++){
		nxt=v[now][i];
		if(nxt==fa)continue;
		if(!pre[nxt]){
			child++;
			low_nxt=dfs(nxt,now);
			lown=min(lown,low_nxt);
			if(low_nxt>=pre[now]){
				is_cut[now]=true;
			}
		}else if(pre[nxt]<pre[now]){
			lown=min(lown,pre[nxt]);
		}
	}
	if(fa==0&&child<2)is_cut[now]=false;
	low[now]=lown;
	return lown;
}
void solve(){
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		if(!pre[i])dfs(i,0);
	}
	for(int i=1;i<=n;i++){
		if(is_cut[i])ans++;
	}
	printf("%d",ans);
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t=1;
	//scanf("%d",&t);
	while(t--){
		solve(); 
	}
	
}
