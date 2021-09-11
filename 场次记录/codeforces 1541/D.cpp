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
const int MAXN=250;
const int bk_sz=3420;
mt19937 rnd(114514);

vector<int> G[MAXN];
ll dp[MAXN][MAXN][MAXN],cnt[MAXN][MAXN][MAXN];
ll mpow(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1){
            ans*=a;
            ans%=MOD;
        }
        a*=a;
        a%=MOD;
        n>>=1;
    }
    return ans;
}
int n;
ll tr[MAXN];
inline int lowbit(int x){
    return x&(-x);
}
void modify(int idx,int n,int val){
    while(idx<=n){
        tr[idx]+=val;
        idx+=lowbit(idx);
    }
}
ll query(int idx){
    ll ans=0;
    while(idx){
        ans+=tr[idx];
        idx-=lowbit(idx);
    }
    return ans;
}
bool vis[MAXN];
void dfs(int now,int fa,int dep){
    if(dp[now][fa][dep])return;
    if(dep==n){
        dp[now][fa][dep]=1;
        cnt[now][fa][dep]=query(n)-query(now);
        cnt[now][fa][dep]%=MOD;
        return;
    }
    vis[now]=1;
    modify(now,n,1);
    vector<int> nxt;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            for(auto to:G[i]){
                if(!vis[to]){
                    dfs(to,i,dep+1);
                    dp[now][fa][dep]+=dp[to][i][dep+1];
                    dp[now][fa][dep]%=MOD;
                    cnt[now][fa][dep]+=cnt[to][i][dep+1];
                    cnt[now][fa][dep]%=MOD;
                }
            }
        }
    }
    // for(auto to:G[now]){
    //     dfs(to,now,dep+1);
        
    // }
    cnt[now][fa][dep]+=(query(n)-query(now))%MOD*dp[now][fa][dep]%MOD;
    modify(now,n,-1);
}

void mainwork(int T){
    scanf("%d",&n);
    for(int i=1,u,v;i<=n;i++){
        scanf("%d%d",&u,&v);
        G[u].eb(v);G[v].eb(u);
    }
    for(int i=1;i<=n;i++){
        dfs(i,0,1);
    }
    ll ans1=0,ans2=0;
    for(int i=1;i<=n;i++){
        ans1+=cnt[i][0][1];
        ans1%=MOD;
        ans2+=dp[i][0][1];
        ans2%=MOD;
    }
    printf("%lld\n",ans1*mpow(ans2,MOD-2)%MOD);
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