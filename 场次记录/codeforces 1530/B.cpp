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
const int MAXN=2050;
const int bk_sz=3420;
mt19937 rnd(114514);

int vis[MAXN][MAXN];
int x[]={-1,0,1,0,-1,-1,1,1};
int y[]={0,-1,0,1,-1,1,-1,1};
int n,m;
bool check(int xx,int yy){
    if(xx!=1&&xx!=n&&yy!=1&&yy!=m){
        return true;
    }
    for(int i=0;i<8;i++){
        if(vis[xx+x[i]][yy+y[i]])return true;
    }
    return false;
}
void mainwork(int T){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            vis[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(check(i,j))continue;
            vis[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d",vis[i][j]);
        }
        puts("");
    }
    puts("");
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