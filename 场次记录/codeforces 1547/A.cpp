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

int x[MAXN],y[MAXN];
void mainwork(int T){
    int n=3;
    for(int i=1;i<=n;i++){
        scanf("%d%d",x+i,y+i);
    }
    if(x[1]==x[2]&&y[1]==y[2]){
        puts("0");
        return;
    }
    int ans=0;
    if(x[1]==x[2]&&x[1]==x[3]){
        int minn=min(y[1],y[2]),maxx=max(y[1],y[2]);
        if(minn<=y[3]&&y[3]<=maxx){
            ans=2;
        }
    }else if(y[1]==y[2]&&y[1]==y[3]){
        int minn=min(x[1],x[2]),maxx=max(x[1],x[2]);
        if(minn<=x[3]&&x[3]<=maxx){
            ans=2;
        }
    }
    ans+=abs(x[1]-x[2])+abs(y[1]-y[2]);
    printf("%d\n",ans);
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