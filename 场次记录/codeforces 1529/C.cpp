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
ll val[MAXN][2];
ll dp[MAXN][2];
void dfs(int now,int fa){
    for(auto to:G[now]){
        if(to==fa)continue;
        dfs(to,now);
        dp[now][0]+=max(dp[to][0]+abs(val[now][0]-val[to][0])
                    ,dp[to][1]+abs(val[now][0]-val[to][1]));
        dp[now][1]+=max(dp[to][0]+abs(val[now][1]-val[to][0])
                    ,dp[to][1]+abs(val[now][1]-val[to][1]));
    }
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&val[i][0],&val[i][1]);
        G[i].clear();
        dp[i][0]=dp[i][1]=0;
    }
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        G[u].eb(v);
        G[v].eb(u);
    }
    dfs(1,0);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
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