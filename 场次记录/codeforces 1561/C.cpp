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

vector<ll> G[MAXN];
pair<ll,ll> dp[MAXN];

bool check(int n,ll val){
    for(int i=1;i<=n;i++){
        if(val<dp[i].first)return false;
        val+=dp[i].second;
    }
    return true;
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        dp[i].first=0;
        G[i].clear();
    }
    for(int i=1;i<=n;i++){
        int k,tmp;
        scanf("%d",&k);
        dp[i].second=k;
        for(int j=1;j<=k;j++){
            scanf("%d",&tmp);
            G[i].eb(tmp);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<G[i].size();j++){
            dp[i].first=max(dp[i].first,G[i][j]-j+1);
        }
    }
    sort(dp+1,dp+n+1);
    // for(int i=1;i<=n;i++){
    //     printf("%lld %lld\n",dp[i].first,dp[i].second);
    // }
    ll l=1,r=1e9+1;
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(n,mid)){
            r=mid;
        }else l=mid+1;
    }
    printf("%lld\n",l);

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