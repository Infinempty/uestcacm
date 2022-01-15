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

ll check(ll i,ll n){
    ll ans;
    if(i<1)return 0;
    else if(i<=(n+1)/2)ans =i*(i+1)/2;
    else {
        ll a=(n+1)/2;
        ans=a*a-(n-i)*(n-i+1)/2;
    }
    return ans;
}
void mainwork(int T){
    ll k,x;
    scanf("%lld%lld",&k,&x);
    ll l=1,r=2ll*k-1,n=2ll*k-1;
    while(l<r){
        ll mid=(l+r+1)>>1;
        ll tmp=check(mid,n);
        if(tmp<x)l=mid;
        else r=mid-1;
    }
    if(check(l,n)<x&&l<n)l++;
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