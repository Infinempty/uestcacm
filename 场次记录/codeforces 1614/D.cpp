// #pragma GCC target("avx2")
// #pragma GCC optimize("Ofast")

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
const int MAXN=20000050;
const int bk_sz=3420;
mt19937 rnd(114514);

int cnt[MAXN],sum[MAXN];
int pri[MAXN],tot;
bool vis[MAXN];
void prework(int n){
    for(int i=2;i<=n;i++){
        if(vis[i])continue;
        pri[++tot]=i;
        for(int j=i+i;j<=n;j+=i){
            vis[j]=1;
        }
    }
}
ll dp[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    int maxx=0;
    for(int i=1,val;i<=n;i++){
        scanf("%d",&val);
        //cnt[val]++;
        maxx=max(maxx,val);
        for(int j=1;j*j<=val;j++){
            if(val%j)continue;
            sum[j]++;
            if(j*j!=val)sum[val/j]++;
        }
    }
    prework(maxx);
    
    // for(int i=maxx;i;i--){
    //     //if(!cnt[i])continue;
    //     for(int j=i;j<=maxx;j+=i){
    //         sum[i]+=cnt[j];
    //     }
    //     dp[i]=1ll*sum[i]*i;
    // }
    // for(int i=maxx;i;i--){
    //     cnt[i]=0;
    //     for(int j=1;i*j<=maxx;j++){
    //         cnt[i]+=mu[j]*sum[i*j];
    //     }
    // }
    ll ans=0;
    for(int i=1;i<=maxx;i++){
        if(!sum[i])continue;
        dp[i]=max(1ll*sum[i]*i,dp[i]);
        for(int j=1;i*pri[j]<=maxx&&j<=tot;j++){
            int now=i*pri[j];
            dp[now]=max(dp[now],sum[now]*(1ll*now-i)+dp[i]);
        }
        ans=max(ans,dp[i]);
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
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}