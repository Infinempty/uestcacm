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

int xx[]={0,1,0,-1,0},yy[]={0,0,1,0,-1};
bool vis[5][5];
ll dp[MAXE][5][5];
ll ans=0;
int n=4;
ll dfs(int x,int y,int dep=n*n){
    if(dep==1){
        return dp[(1ll<<(n*n))-1][x][y]=1;
    }
    vis[x][y]=1;
    ll sta=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sta<<=1;
            sta+=vis[i][j];
        }
    }
    if(dp[sta][x][y]){
        vis[x][y]=0;
        return dp[sta][x][y];
    }
    ll ans=0;
    for(int i=1;i<=4;i++){
        if(x+xx[i]<=0||y+yy[i]>n||x+xx[i]>n||y+yy[i]<=0)continue;
        if(!vis[x+xx[i]][y+yy[i]]){
            ans+=dfs(x+xx[i],y+yy[i],dep-1);
        }
    }
    vis[x][y]=0;
    return dp[sta][x][y]=ans;
}
void mainwork(int T){
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=dfs(i,j);
        }
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
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}