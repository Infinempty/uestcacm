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
const int MAXN=100050;
const int bk_sz=3420;
mt19937 rnd(114514);

int pri[MAXN],mu[MAXN],tot;
bool vis[MAXN];
void prework(int n){
    mu[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            pri[++tot]=i;
            mu[i]=-1;
        }
        for(int j=1;i*pri[j]<=n&&j<=tot;j++){
            vis[i*pri[j]]=1;
            mu[i*pri[j]]=-mu[i];
            if(i%pri[j]==0){
                mu[i*pri[j]]=0;
                break;
            }
        }
    }
}
int lb[MAXN],rb[MAXN];
ll dp[MAXN],sum[MAXN];
ll cal(int n,int m,ll gcdd){
    m/=gcdd;
    for(int i=0;i<=m;i++){
        sum[i]=1;
        dp[i]=0;
    }
    for(int i=1;i<=n;i++){
        int l=(lb[i]+gcdd-1)/gcdd,r=rb[i]/gcdd;
        for(int j=m;j>=l;j--){
            dp[j]=sum[j-l]-(j<=r?0ll:sum[j-r-1]);
            dp[j]%=MOD;
            //j-r-1<0,j<r+1,j<=r
        }
        for(int i=0;i<=m;i++)sum[i]=(sum[i-1]+dp[i])%MOD;
        for(int i=0;i<=m;i++)dp[i]=0;
    }
    return sum[m];
}
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",lb+i,rb+i);
    }
    ll ans=0;
    for(ll gcdd=1;gcdd<=m;gcdd++){
        if(!mu[gcdd])continue;
        ll tmp=cal(n,m,gcdd);
        ans=(ans+tmp*mu[gcdd]+MOD)%MOD;
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
    prework(MAXN-50);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}