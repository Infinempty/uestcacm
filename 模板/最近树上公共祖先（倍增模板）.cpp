#include<bits/stdc++.h>
#define ll long long
#define INF 1e14
using namespace std;
const int maxn=500000+10;

struct edge{
	int u,v;
	ll w;
};
vector<edge> e1[maxn];
int vis[maxn],dep[maxn],fa[maxn][25];
int n,m,T=0,pos=0;
ll minn=0;
ll dis[2][maxn][25];
void dfs(int fath,int n,int t){
	if(vis[n])return;
	dep[n]=t;
	vis[n]=1;
	fa[n][0]=fath;
	for(int i=1;i<=22;i++){
		if(fa[fa[n][i-1]][i-1]==0)break;
		fa[n][i]=fa[fa[n][i-1]][i-1];
	}
	for(int i=0;i<e1[n].size();i++){
		if(vis[e1[n][i].v]!=0)continue;
		dfs(n,e1[n][i].v,t+1);
	}
}
int LCA(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int de=dep[y]-dep[x];
	for(int i=22;dep[x]<dep[y];i--){
		de=dep[y]-dep[x];
		if(1<<i&de){
			y=fa[y][i];
		}
	}
	if(x==y)return x;
	for(int i=22;;i--){
		if(fa[y][i]!=fa[x][i]){
			y=fa[y][i];
			x=fa[x][i];
		}
		if(fa[y][0]==fa[x][0]&&x!=y)break;
	}
	return fa[x][0];
}


void solve(){
	//minn是最小生成树权值 
    ll w,ans=INF,tmp=INF;
    int u,v,lca,q;
    scanf("%d %d %d",&n,&q,&m);
    for(int i=1;i<n;i++){
    	scanf("%d %d",&u,&v);
    	e1[u].push_back({u,v,0});
    	e1[v].push_back({v,u,0});
	}
	ans=INF;
	dfs(0,m,1);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&u,&v);
		printf("%d\n",LCA(u,v));
	}
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
