#include<bits/stdc++.h>
#define ll long long
#define INF 1e17
#define int ll
using namespace std;
const int maxn=300000+10;

struct edge{
	ll u,v;
	ll w;
}e[maxn];
vector<edge> e1[maxn];
ll fa_fi[maxn],vis[maxn],dep[maxn],fa[maxn][25],vis_e[maxn];
ll n,m,T=0,pos=0;
ll minn=0;
ll dis[2][maxn][25];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
ll find(ll x){
	if(fa_fi[x]==x)return x;
	fa_fi[x]=find(fa_fi[x]);
	return fa_fi[x];
}
void kruskal(){
	ll u,v;
	for(int i=1;i<=n;i++)fa_fi[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		u=find(e[i].u),v=find(e[i].v);
		if(u==v)continue;
		minn+=e[i].w;
		vis_e[i]=1;
		e1[e[i].u].push_back({e[i].u,e[i].v,e[i].w});
		e1[e[i].v].push_back({e[i].v,e[i].u,e[i].w});
		fa_fi[v]=u;
		if(T==n-1){
			break;
		}
	}
}

void dfs(ll fath,ll n,ll t){
	dep[n]=t;
	fa[n][0]=fath;
	for(int i=0;i<e1[n].size();i++){
		if(e1[n][i].v==fath)continue;
		dis[0][e1[n][i].v][0]=e1[n][i].w;
		dis[1][e1[n][i].v][0]=-1*INF;
		dfs(n,e1[n][i].v,t+1);
	}
}
void cal(){
	for(int i=1;i<=18;i++){
		for(int j=1;j<=n;j++){
			fa[j][i]=fa[fa[j][i-1]][i-1];
			dis[0][j][i]=max(dis[0][j][i-1],dis[0][fa[j][i-1]][i-1]);
			dis[1][j][i]=max(dis[1][j][i-1],dis[1][fa[j][i-1]][i-1]);
			if(dis[0][j][i-1]>dis[0][fa[j][i-1]][i-1])dis[1][j][i]=max(dis[1][j][i-1],dis[0][fa[j][i-1]][i-1]);
			else if(dis[0][j][i-1]<dis[0][fa[j][i-1]][i-1])dis[1][j][i]=max(dis[1][j][i],dis[0][j][i-1]);
		}
	}
}
ll LCA(ll x,ll y){
	if(dep[x]>dep[y])swap(x,y);
	ll de=dep[y]-dep[x];
	for(int i=22;dep[x]<dep[y];i--){
		de=dep[y]-dep[x];
		if(1<<i&de){
			y=fa[y][i];
		}
	}
	if(x==y)return x;
	for(int i=18;;i--){
		if(fa[y][i]!=fa[x][i]){
			y=fa[y][i];
			x=fa[x][i];
		}
		if(fa[y][0]==fa[x][0]&&x!=y)break;
	}
	return fa[x][0];
}
ll query(ll x,ll y,ll val){
	ll ans=-INF;
	for(int i=18;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			if(val!=dis[0][x][i])ans=max(ans,dis[0][x][i]);
			else ans=max(ans,dis[1][x][i]);
			x=fa[x][i];
		}
	}
	return ans;
}

void solve(){
	//minn是最小生成树权值 
	
	//非严格次小生成树只需要维护最大值而非最大值和次大值  请自行修改 
    ll w,ans=INF,tmp=INF,maxu,maxv;
    ll u,v,lca;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=m;i++){
    	scanf("%lld %lld %lld",&u,&v,&w);
    	e[i].u=u;
    	e[i].v=v;
    	e[i].w=w;
	}
	dis[1][1][0]=-1*INF;
	kruskal();
	ans=INF;
	dfs(0,1,1);
	cal();
	/*for(int i=1;i<=3;i++){
		cout<<i<<" "<<fa[i][1]<<endl;
		cout<<dis[0][i][1]<<endl;
	}*/
	for(int i=1;i<=m;i++){
		u=e[i].u,v=e[i].v,w=e[i].w;
		if(vis_e[i])continue;
		lca=LCA(e[i].u,e[i].v);
		maxu=query(u,lca,w);
		maxv=query(v,lca,w);
		ans=min(ans,minn-max(maxu,maxv)+w);
	}
	printf("%lld",ans);
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
