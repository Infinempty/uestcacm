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
const int MAXE=5000050;
const int MAXN=200050;
const int bk_sz=3420;
mt19937 rnd(114514);

int bel[MAXN];
ll tr[2][MAXN<<2][2];
vector<int> G[MAXN];

int head[MAXN],sz[MAXN],fa[MAXN],st[MAXN],ed[MAXN],rev[MAXN],son[MAXN],dep[MAXN];
int dfs_clock;

void dfs(int now,int f,int dp=0){
    st[now]=++dfs_clock;
    sz[now]=1;
    fa[now]=f;
    int maxx=0;
    dep[now]=dp+1;
    for(auto to:G[now]){
        if(to==f)continue;
        dfs(to,now,dp+1);
        sz[now]+=sz[to];
        if(sz[to]>maxx){
            maxx=sz[to];
            son[now]=to;
        }
    }
    ed[now]=dfs_clock;
}
void dfs2(int now,int top){
    head[now]=top;
    if(son[now])dfs2(son[now],top);
    for(auto to:G[now]){
        if(to==fa[now]||to==son[now])continue;
        dfs2(to,to);
    }
}
void build(int id,int lb,int rb,int whi){
    
}


void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",bel+i);
    }
    for(int i,u,v=1;i<n;i++){
        scanf("%d%d",&u,&v);
        G[u].eb(v);
        G[v].eb(u);
    }

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