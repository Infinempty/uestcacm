//#pragma GCC target("avx2")
//#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define lc(x) ((x)<<1)
#define rc(x) (((x)<<1)|1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ll MOD=1e9+7;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXE=10050;
const int MAXN=250;
const int bk_sz=3420;
mt19937 rnd(114514);

struct E{
    int from,to,nxt;
    ll cap,flow;
}edges[MAXE];

int head[MAXN],tot;
void Addedge(int u,int v,ll cap){
    edges[tot]={u,v,head[u],cap,0};
    head[u]=tot++;
    edges[tot]={v,u,head[v],0,0};
    head[v]=tot++;
}
int n,m,s,t;
bool vis[MAXN];
int dep[MAXN];
bool bfs(){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    queue<int> q;
    q.push(s);
    dep[s]=0;
    vis[s]=1;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=head[now];~i;i=edges[i].nxt){
            E &e=edges[i];
            if(!vis[e.to]&&e.cap>e.flow){
                dep[e.to]=dep[now]+1;
                vis[e.to]=1;
                q.push(e.to);
            }
        }
    }
    return vis[t];
}
int cur[MAXN];
ll dfs(int now,ll a){
    if(now==t||!a)return a;
    ll flow=0,f;
    for(int &i=cur[now];~i;i=edges[i].nxt){
        E &e=edges[i];
        if(dep[now]+1==dep[e.to]&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
            e.flow+=f;
            edges[i^1].flow-=f;
            flow+=f;a-=f;
            if(!a)break;
        }
    }
    return flow;
}
ll maxflow(){
    ll flow=0;
    while(bfs()){
        for(int i=1;i<=n;i++){
            cur[i]=head[i];
        }
        flow+=dfs(s,LINF);
    }
    return flow;
}

void mainwork(int T){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=n;i++)head[i]=-1;
    ll cap;
    for(int i=1,u,v;i<=m;i++){
        scanf("%d%d%lld",&u,&v,&cap);
        Addedge(u,v,cap);
    }
    // for(int i=0;i<tot;i++){
    //     printf("%d %d %d %d\n",i,edges[i].from,edges[i].to,edges[i].nxt);
    // }
    ll ans=maxflow();
    printf("%lld\n",ans);
}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}