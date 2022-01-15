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

ll dp[MAXN];
ll mpow(ll a,ll n,ll m){
    ll ans=1;
    while(n){
        if(n&1){
            ans*=a;
            ans%=m;
        }
        a*=a;
        a%=m;
        n>>=1;
    }
    return ans;
}
unordered_map<ll,bool> mp;
void mainwork(int T){
    ll p,q;
    ll n,m;
    scanf("%lld%lld",&p,&q);
    scanf("%lld%lld",&n,&m);
    ll ans=0;
    vector<ll> sum;
    int len=-1;
    for(ll i=1;i<=n;i++){
        ll tmp=(mpow(p,i,m)*mpow(i,q,m))%m;
        if(mp.count(tmp)){
            len=i-1;
            break;
        }
        mp[tmp]=1;
        if(!sum.empty())tmp+=sum.back();
        tmp%=m;
        sum.push_back(tmp);
        
    }
    if(len==-1)len=n;
    ans=1ll*n/len * sum.back();
    ans%=m;
    if(n%len)ans+=sum[n%len-1];
    ans%=m;
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