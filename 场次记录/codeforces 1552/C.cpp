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
bool vis[MAXN];
void mainwork(int T){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=2*n;i++)vis[i]=0;
    for(int i=1;i<=k;i++){
        scanf("%d%d",x+i,y+i);
        vis[x[i]]=vis[y[i]]=1;
        if(x[i]>y[i])swap(x[i],y[i]);
    }
    vector<int> unuse;
    for(int i=1;i<=2*n;i++){
        if(!vis[i])unuse.eb(i);
    }
    int sz=unuse.size()/2;
    for(int i=0;i<sz;i++){
        x[k+i+1]=unuse[i];
        y[k+i+1]=unuse[i+sz];
    }
    int ans=0;
    // for(int i=1;i<=n;i++){
    //     printf("%d %d\n",x[i],y[i]);
    // }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(x[i]<x[j]&&y[i]<y[j]&&x[j]<y[i])ans++;
            if(x[i]>x[j]&&y[i]>y[j]&&x[i]<y[j])ans++;
            //ans++;
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
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}