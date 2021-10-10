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
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",a+i);
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    ll x,y;
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&x,&y);
        int idx=lower_bound(a+1,a+n+1,x)-a;
        if(idx==1){
            ll ans=max(0ll,y-sum+a[1]);
            printf("%lld\n",ans);
        }else if(idx>n){
            ll ans=max(0ll,y-sum+a[n])+x-a[n];
            printf("%lld\n",ans);
        }else{
            ll tmp=max(0ll,y-sum+a[idx]);
            ll tmp2=max(0ll,y-sum+a[idx-1])+x-a[idx-1];
            printf("%lld\n",min(tmp,tmp2));
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