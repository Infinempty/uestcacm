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
const int MAXN=2000050;
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
    for(ll i=1;i<=n;i++){
        fac[i]=fac[i-1]*i;
        fac[i]%=MOD;
    }
    inv[0]=1;
    inv[n]=mpow(fac[n],MOD-2);
    for(ll i=n-1;i;i--){
        inv[i]=inv[i+1]*(i+1)%MOD;
    }
}
ll getC(int n,int m){
    if(n<m||n<0||m<0)return 0ll;
    return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
void mainwork(int T){
    ll n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    prework(n+m);
    if(m<=n-k-1){
        puts("0");
        return;
    }
    ll ans=getC(n+m,m)-getC(n+m,m+k+1);
    ans=(ans+MOD)%MOD;
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