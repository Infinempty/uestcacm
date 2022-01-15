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

ll fac[MAXN],inv[MAXN];
ll mpow(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1){
            ans=ans*a%MOD;
        }
        a=a*a%MOD;
        n>>=1;
    }
    return ans;
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    fac[0]=inv[0]=1;
    for(ll i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%MOD;
    }
    inv[n]=mpow(fac[n],MOD-2);
    for(ll i=n-1;i;i--){
        inv[i]=inv[i+1]*(i+1)%MOD;
        //printf("%lld ",inv[i]);
    }
    ll ans=fac[n]*inv[n/2]%MOD*inv[n-n/2]%MOD;
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