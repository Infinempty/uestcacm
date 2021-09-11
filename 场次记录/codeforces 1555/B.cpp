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

void mainwork(int T){
    ll H,W,x1,x2,y1,y2,h,w;
    cin>>H>>W>>x1>>y1>>x2>>y2>>h>>w;
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    if(!((H-x2+x1>=h&&W>=w)||(W-y2+y1>=w&&H>=h))){
        puts("-1");
        return;
    }
    ll ans=LINF;
    ll hh,ww;
    hh=H;
    ww=W-y2;
    if(W-y2+y1>=w)ans=min(ans,max(0ll,w-ww));
    if(W-y2+y1>=w)ans=min(ans,max(0ll,w-y1));
    if(H-x2+x1>=h)ans=min(ans,max(0ll,h-H+x2));
    if(H-x2+x1>=h)ans=min(ans,max(0ll,h-x1));
    printf("%lld\n",ans);
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