#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct ed{
	ll to,val;
}temp;
vector<ed> v[100050];
ll vis[100050],fa[100050][25],dis[100050][25],dep[100050];


void dfs(int fath,int n,int t){
	if(vis[n])return;
	dep[n]=t;
	vis[n]=1;
	fa[n][0]=fath;
	for(int i=1;i<=22;i++){
		if(fa[fa[n][i-1]][i-1]==0)break;
		fa[n][i]=fa[fa[n][i-1]][i-1];
		dis[n][i]=min(dis[n][i-1],dis[fa[n][i-1]][i-1]);
	}
	for(int i=0;i<v[n].size();i++){
		if(vis[v[n][i].to]!=0)continue;
		dis[v[n][i].to][0]=v[n][i].val;
		dfs(n,v[n][i].to,t+1);
	}
}

ll query(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	ll ans=1e18;
	int de=dep[y]-dep[x];
	for(int i=16;dep[x]<dep[y];i--){
		de=dep[y]-dep[x];
		if(1<<i&de){
			ans=min(dis[y][i],ans);
			y=fa[y][i];
		}
	}
	if(x==y)return ans;
	for(int i=16;;i--){
		if(fa[y][i]!=fa[x][i]){
			ans=min(ans,min(dis[x][i],dis[y][i]));
			y=fa[y][i];
			x=fa[x][i];
		}
		if(fa[y][0]==fa[x][0]&&x!=y)break;
	}
	ans=min(ans,min(dis[y][0],dis[x][0]));
	return ans;
}
int main() {
    int n,q;
    int x,y,val;
    cin>>n>>q;
    for(int i=1;i<n;i++){
    	cin>>x>>y>>val;
    	temp.to=x;
    	temp.val=val;
    	v[y].push_back(temp);
    	temp.to=y;
    	v[x].push_back(temp);
	}
	fa[1][0]=0;
	dfs(0,1,1);
	/*for(int i=1;i<=n;i++){
		for(int j=0;j<4;j++){
			cout<<fa[i][j]<<" "<<dis[i][j]<<endl;
		}
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<query(x,y)<<endl;
	}
}
