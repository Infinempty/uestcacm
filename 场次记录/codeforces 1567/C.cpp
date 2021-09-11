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

ll pos[MAXN];
ll vv[]={1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1,0};
ll ans=0;
void dfs(int dep,ll now){
    if(dep==0){
        ans+=now;
        return;
    }
    if(pos[dep]&&dep>2){
        pos[dep-2]+=10;
        pos[dep]--;
        dfs(dep-1,now*vv[pos[dep]]);
        pos[dep]++;
        pos[dep-2]-=10;
    }
    dfs(dep-1,now*vv[pos[dep]]);
}
void mainwork(int T){
    ll n;
    scanf("%lld",&n);
    ans=0;
    int cnt=0;
    ll tmp=n;
    while(tmp){
        cnt++;
        tmp/=10;
    }
    tmp=n;
    for(int i=1;i<=cnt;i++){
        pos[i]=tmp%10;
        tmp/=10;
    }
    dfs(cnt,1);
    printf("%lld\n",ans-2);
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