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
const ll LINF=2e18;
const int INF=0x3f3f3f3f;
const int MAXE=5000050;
const int MAXN=200050;
const int bk_sz=3420;
mt19937 rnd(114514);

ll a[MAXN];
bool check(ll now,ll k,int n){
    ll idx=lower_bound(a+1,a+n+2,now)-a;
    if(a[idx]>now)idx--;
    return now-idx>=k;
}
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    a[n+1]=LINF;
    for(int t=1;t<=m;t++){
        ll k;
        scanf("%lld",&k);
        ll l=1,r=1.5e18;
        while(l<r){
            ll mid=(l+r)>>1;
            if(check(mid,k,n)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        printf("%lld\n",l);
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