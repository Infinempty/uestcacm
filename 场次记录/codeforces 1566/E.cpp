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
int typ[MAXN];
vector<pair<int,int> > bud;
void dfs(int now,int fa){
    bool ok=0;
    for(auto to:G[now]){
        if(to==fa)continue;
        dfs(to,now);
    }
    int cnt=0;
    for(auto to:G[now]){
        cnt+=typ[to]==1;
    }
    if(!cnt){
        typ[now]=1;
        return;
    }
    typ[now]=2;
    if(now!=1)bud.emplace_back(mkp(now,cnt));
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    bud.clear();
    for(int i=1;i<=n;i++){
        typ[i]=-1;
        G[i].clear();
    }
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        G[u].eb(v);
        G[v].eb(u);
    }
    ll ans=0;
    dfs(1,0);
    for(auto to:G[1]){
        ans+=typ[to]==1;
    }
    if(ans==0)ans++;
    for(auto now:bud){
        ans+=now.second-1;
    }
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