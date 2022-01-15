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

ll dp[MAXN][2];
void mainwork(int T){
    int n,k;
    scanf("%d%d",&n,&k);
    dp[0][0]=dp[0][1]=1;
    for(int i=1;i<=n;i++){
        int a,b,c=1;
        scanf("%d%d",&a,&b);
        int aa,bb;
        for(int j=1;j<=k;j++)dp[j][i&1]=dp[j][!(i&1)];
        for(int j=1;j<=a;j++){
            bb=j*b;
            for(int l=k;l>=bb;l--){
                dp[l][i&1]+=dp[l-bb][!(i&1)];
                dp[l][i&1]%=MOD;
            }
        }
    }
    printf("%lld\n",dp[k][n&1]);
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