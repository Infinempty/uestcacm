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
const int MAXN=150;
const int bk_sz=3420;
mt19937 rnd(114514);

struct E{
    int from,to,cap,flow,nxt;
}edges[MAXE];
int head[MAXN],tot;
void addedge(int u,int v,int cap){
    edges[tot]={u,v,cap,0,head[u]};
    head[u]=tot++;
    edges[tot]={v,u,0,0,head[v]};
    head[v]=tot++;
}
int n,m,s,t;
int dep[MAXN],cur[MAXN];
bool vis[MAXN];
bool bfs(){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    queue<int> q;
    q.push(s);
    vis[s]=1;
    dep[s]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=head[now];~i;i=edges[i].nxt){
            E &e=edges[i];
            if(!vis[e.to]&&e.cap>e.flow){
                q.push(e.to);
                dep[e.to]=dep[now]+1;
                vis[e.to]=1;
            }
        }
    }
    return vis[t];
}
int dfs(int now,int a){
    if(now==t||!a)return a;
    int flow=0,f;
    for(int &i=cur[now];~i;i=edges[i].nxt){
        E &e=edges[i];
        if(dep[e.to]==dep[now]+1&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
            flow+=f;a-=f;
            e.flow+=f;
            edges[i^1].flow-=f;
            if(!a)break;
        }
    }
    return flow;
}
int maxflow(){
    int flow=0;
    while(bfs()){
        for(int i=1;i<=n;i++){
            cur[i]=head[i];
        }
        flow+=dfs(s,INF);
    }
    return flow;
}

void mainwork(int T){
    int k;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+2;i++)head[i]=-1;
    for(int i=1;i<=m;i++){
        addedge(n+1,i,1);
    }
    for(int i=m+1;i<=n;i++){
        addedge(i,n+2,1);
    }
    int u,v;
    // for(int i=1,u,v;i<=k;i++){
    //     scanf("%d%d",&u,&v);
    //     addedge(u,v,1);
    // }
    while(scanf("%d%d",&u,&v)!=EOF){
        addedge(u,v,1);
    }
    s=n+1,t=n+2;
    n+=2;
    int ans=maxflow();
    printf("%d\n",ans);
    
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