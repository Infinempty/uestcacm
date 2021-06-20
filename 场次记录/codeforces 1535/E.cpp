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
const int MAXN=500050;
const int bk_sz=3420;
mt19937 rnd(114514);

ll a[MAXN],c[MAXN];
ll fa[MAXN][20];
int getidx(int now){
    for(int i=19;~i;i--){
        if(fa[now][i]==-1||a[fa[now][i]]<=0)continue;
        now=fa[now][i];
    }
    return now;
}
void mainwork(int T){
    int m;
    scanf("%d%lld%lld",&m,a,c);
    for(int i=0;i<20;i++)fa[0][i]=-1;
    for(int i=1;i<=m;i++){
        int opt,p;
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d",&p);
            scanf("%lld%lld",a+i,c+i);
            fa[i][0]=p;
            for(int j=1;j<20;j++){
                if(fa[i][j-1]==-1)fa[i][j]=-1;
                else fa[i][j]=fa[fa[i][j-1]][j-1];
            }
        }else{
            int v;ll w;
            scanf("%d%lld",&v,&w);
            ll ton=0,cost=0;
            while(w>0){
                int idx=getidx(v);
                ll minn=min(w,a[idx]);
                w-=minn;
                a[idx]-=minn;
                ton+=minn;
                cost+=c[idx]*minn;
                if(idx==v)break;
            }
            printf("%lld %lld\n",ton,cost);
            fflush(stdout);
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