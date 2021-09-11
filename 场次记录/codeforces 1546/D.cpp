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

char s[MAXN];
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
void prework(ll n){
    fac[0]=inv[0]=1;
    for(ll i=1;i<=n;i++){
        fac[i]=fac[i-1]*i;
        fac[i]%=MOD;
    }
    inv[n]=mpow(fac[n],MOD-2);
    for(ll i=n-1;~i;i--){
        inv[i]=inv[i+1]*(i+1)%MOD;
    }
}
ll nCr(ll n,ll r){
    return fac[n]*inv[r]%MOD*inv[n-r]%MOD;
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    int cnt1=0,tmp=0,cnt0=0;
    for(int i=1;i<=n;){
        tmp=0;
        if(s[i]=='0'){
            i++;
            cnt0++;
            continue;
        }
        int now=i;
        while(s[now+1]=='1')now++;
        tmp=(now-i+1);
        if(tmp&1)tmp--;
        cnt1+=tmp/2;
        i=now+1;
    }
    
    printf("%lld\n",nCr(cnt1+cnt0,cnt1));

}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    int t=1;
    scanf("%d",&t);
    prework(MAXN-50);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}