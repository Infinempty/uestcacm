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
const int MAXN=50050;
const int bk_sz=3420;
mt19937 rnd(114514);

ll inv[MAXN],fac[MAXN],ifac[MAXN];
void prework(int n){
    inv[1]=1;
    fac[0]=ifac[0]=1;
    for(ll i=1;i<=n;i++){
        fac[i]=fac[i-1]*i%MOD;
    }
    for(ll i=2;i<=n;i++){
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    for(ll i=1;i<=n;i++){
        ifac[i]=ifac[i-1]*inv[i]%MOD;
    }
}
ll a[21][MAXN];
ll pos[MAXN];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    prework(max(n,m));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",a[i]+j);
        }
    }
    ll ans=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n+1;j++){
            pos[j]=0;
        }
        for(int j=1;j<=n;j++){
            pos[a[j][i]]++;
        }
        ll now=1,tot=0;
        for(ll j=1;j<=n+1;j++){
            while(pos[j]){
                now=(now*(j-1-tot))%MOD;
                tot++;
                pos[j]--;
            }
            
        }
        ans+=now;
        ans%=MOD;
    }
    ans=((1ll*m*fac[n]%MOD-ans+MOD)%MOD*ifac[n]%MOD);
    printf("%lld",ans);

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