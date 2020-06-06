#include<bits/stdc++.h>
#define ll long long
#define MAX 1e18
using namespace std;
vector<int> v[100050];
int degp[105],degn[105],vis[105],cnt[105];
int n,m;
void dfs(int n){
	if(vis[n])return;
	vis[n]=1;
	for(int i=0;i<v[n].size();i++){
		dfs(v[n][i]);
	}
}

void solve(){
	scanf("%d",&n);
	int x,y,maxx=0,tmp=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		degp[x]++;
		degn[y]++;
		cnt[x]=1;
		cnt[y]=1;
		v[x].push_back(y);
		maxx=max(maxx,max(x,y));
	}
	tmp=x;
	x=y=0;
	for(int i=1;i<=100;i++){
		if(degp[i]==degn[i])continue;
		if(degp[i]==degn[i]+1){
			if(x){
				printf("-1");
				return; 
			}
			x=i;
		}
		if(degp[i]+1==degn[i]){
			if(y){
				printf("-1");
				return;
			}
			y=i;
		}
	}
	if(x&&y){
		printf("%d",x*y);
		return;
	}
	dfs(tmp);
	for(int i=1;i<=100;i++){
		if(!cnt[i])continue;
		if(!vis[i]){
			printf("-1");
			return;
		}
	}
	printf("%d",maxx*maxx);
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
