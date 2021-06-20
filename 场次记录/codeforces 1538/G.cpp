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

ll x,y,a,b;
bool check(ll now){
    if(a==b){
        return min(x,y)/a>=now;
    }
    ll lb=ceil(1.0*(a*now-y)/(a-b));
    ll rb=floor(1.0*(x-now*b)/(a-b));
    lb=max(lb,0ll);
    rb=min(now,rb);
    return lb<=rb;
}
void mainwork(int T){
    
    scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
    if(a<b)swap(a,b);
    ll l=0,r=1e10;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
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