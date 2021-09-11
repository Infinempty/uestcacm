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
const int MAXN=3000050;
const int bk_sz=3420;
mt19937 rnd(114514);

ll fac[MAXN],inv[MAXN];
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
void prework(int n){
    fac[1]=1;
    fac[0]=1;
    for(int i=2;i<=n;i++){
        fac[i]=fac[i-1]*i;
        //printf("%lld\n",fac[i]);
        fac[i]%=MOD;
    }
    inv[0]=1;
    inv[n]=mpow(fac[n],MOD-2);
    for(int i=n-1;i;i--){
        inv[i]=inv[i+1]*(i+1)%MOD;
        //printf("%lld\n",inv[i]);
    }
}
ll nCr(ll n,ll r){
    if(n<0||r<0||n<r)return 0;
    return fac[n]*inv[n-r]%MOD*inv[r]%MOD;
}
ll dp[MAXN][3];
void mainwork(int T){
    int n,q;
    scanf("%d%d",&n,&q);
    prework(3*n+1);
    //printf("%lld\n",nCr(10,2));
    dp[0][0]=dp[0][1]=dp[0][2]=n;
    ll inv3=mpow(3,MOD-2);
    for(int i=1;i<n*3;i++){
        dp[i][0]=(nCr(3*n,i+1)-dp[i-1][0]*2-dp[i-1][1]+3*MOD)%MOD*inv3%MOD;
        dp[i][1]=(dp[i][0]+dp[i-1][0])%MOD;
        //dp[i][2]=(dp[i][1]+dp[i-1][1])%MOD;
    }
    while(q--){
        int x;
        scanf("%d",&x);
        if(x==3*n){
            puts("1");
        }else{
            printf("%lld\n",((dp[x][0]+nCr(3*n,x)))%MOD);
        }
    }
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