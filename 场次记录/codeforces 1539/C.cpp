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

ll a[MAXN];
void mainwork(int T){
    int n;
    ll k,x;
    scanf("%d%lld%lld",&n,&k,&x);
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1);
    vector<ll>tmp;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]>x){
            ll cnt=(a[i]-a[i-1])/x-((a[i]-a[i-1])%x==0);
            if(cnt)tmp.eb(cnt);
        }
    }
    sort(all(tmp));
    int ans=tmp.size()+1;
    for(auto i:tmp){
        if(k>=i){
            k-=i;
            ans--;
        }
    }
    printf("%d\n",ans);
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