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

ll MOD=1e9+7;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXE=5000050;
const int MAXN=4000050;
const int bk_sz=3420;
mt19937 rnd(114514);

ll dp[MAXN],sum[MAXN],sub[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    scanf("%lld",&MOD);
    sum[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=sum[i-1]+sub[i];
        dp[i]%=MOD;
        for(int len=2;i*len<=n;len++){
            int sta=i*len,ed=min(n,i*len+len-1);
            sub[sta]+=dp[i];
            sub[sta]%=MOD;
            sub[ed+1]-=dp[i];
            sub[ed+1]+=MOD;
            sub[ed+1]%=MOD;
        }
        sum[i]=dp[i]+dp[i];
        if(i==1)sum[i]--;
        sum[i]%=MOD;
    }
    printf("%lld\n",dp[n]);
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