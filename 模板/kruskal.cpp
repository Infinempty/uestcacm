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
ll fa_fi[maxn],vis[maxn];
ll n,m,T=0,pos=0;
ll minn=0;
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

void solve(){
	//e存原始图 e1存最小生成树 
    ll w,ans=INF,tmp=INF,maxu,maxv;
    ll u,v,lca;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=m;i++){
    	scanf("%lld %lld %lld",&u,&v,&w);
    	e[i].u=u;
    	e[i].v=v;
    	e[i].w=w;
	}
	kruskal();
	ans=INF;
	
	printf("%lld",minn);
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
