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

vector<int> G[MAXN];
int dfs_clock,n;
ll ans;
bool vis[MAXN];
void dfs(int now){
    vis[now]=1;
    dfs_clock++;
    for(auto to:G[now]){
        if(vis[to])continue;
        if(dfs_clock==n)return;
        while(to!=dfs_clock+1&&!vis[to]){
            ans++;
            dfs(dfs_clock+1);
        }
        if(!vis[to])dfs(to);
    }
    while(now==1&&dfs_clock!=n){
        ans++;
        dfs(dfs_clock+1);
    }
}
void mainwork(int T){
    int m;
    scanf("%d%d",&n,&m);
    dfs_clock=ans=0;
    for(int i=1;i<=n;i++){
        G[i].clear();
        vis[i]=0;
    }
    for(int i=1,u,v;i<=m;i++){
        scanf("%d%d",&u,&v);
        if(u==v)continue;
        G[u].eb(v);
        G[v].eb(u);
    }
    for(int i=1;i<=n;i++){
        sort(all(G[i]));
        G[i].erase(unique(all(G[i])),G[i].end());
    }
    dfs(1);
    printf("%lld\n",ans);

}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}