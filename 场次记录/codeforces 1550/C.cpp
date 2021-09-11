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

int a[MAXN];
int x[]={1,1,2,1,1,2,2,2,3,1,1,3},y[]={2,3,3,2,4,4,3,4,4,3,4,4},z[]={3,2,1,4,2,1,4,3,2,4,3,1};
bool check(int idx){
    for(int i=0;i<12;i++){
        int dis1=abs(a[x[i]+idx-1]-a[y[i]+idx-1])+abs(x[i]-y[i]);
        int dis2=abs(a[x[i]+idx-1]-a[z[i]+idx-1])+abs(x[i]-z[i]);
        int dis3=abs(a[z[i]+idx-1]-a[y[i]+idx-1])+abs(z[i]-y[i]);
        if(dis1+dis2==dis3)return 1;
    }
    return 0;
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    ll ans=n+n-1;
    for(int i=1;i+2<=n;i++){
        if(a[i+1]<a[i]&&a[i+1]<a[i+2])ans++;
        if(a[i+1]>a[i]&&a[i+1]>a[i+2])ans++;
    }
    for(int i=1;i+3<=n;i++){
        if(check(i))continue;
        ans++;
    }
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