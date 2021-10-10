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

const ll MOD=998244353;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXE=5000050;
const int MAXN=200050;
const int bk_sz=3420;
mt19937 rnd(114514);

int dep[MAXN],fa[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];
int bfs(int root,int n){
    queue<pair<int,int> >q;
    q.push(mkp(root,0));
    for(int i=1;i<=n;i++)vis[i]=0;
    vis[root]=1;
    while(!q.empty()){
        int now=q.front().first;
        int dp=q.front().second;
        q.pop();
        dep[now]=dp;
        for(auto to:G[now]){
            if(vis[to])continue;
            q.push(mkp(to,dp+1));
            vis[to]=1;
            fa[to]=now;
        }
    }
    int maxx=0;
    for(int i=1;i<=n;i++)maxx=max(maxx,dep[i]);
    for(int i=1;i<=n;i++){
        if(dep[i]==maxx)return i;
    }
}
int sz[MAXN];
void dfs(int now,int fa,int tag,int dep){
    if(dep==tag){
        sz[now]=1;
        return;
    }
    for(auto to:G[now]){
        if(to==fa)continue;
        dfs(to,now,tag,dep+1);
        sz[now]+=sz[to];
    }
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].eb(v);
        G[v].eb(u);
    }
    int root=bfs(1,n);
    int t=bfs(root,n);
    int tag=(dep[t]+1)/2,x=dep[t];
    vector<int> tmp;
    while(dep[t]^(tag))t=fa[t];
    if(x&1){
        dfs(t,fa[t],tag,1);
        tmp.eb(t);
        tmp.eb(fa[t]);
        dfs(fa[t],t,tag,1);
    }else{
        for(auto to:G[t]){
            dfs(to,t,tag,1);
            tmp.eb(to);
        }
    }
    ll ans=1;
    ll sum=0;
    for(auto now:tmp){
        ans*=(1ll*sz[now]+1)%MOD;
        ans%=MOD;
        sum+=sz[now];
        sum%=MOD;
    }
    printf("%lld\n",(ans-sum-1+MOD+MOD)%MOD);

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