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
int dp[MAXN];
int sum;
vector<int> G[MAXN];
void dfs(int now,int fa){
    for(auto to:G[now]){
        if(to==fa)continue;
        dfs(to,now);
        if(dp[to]!=sum)dp[now]^=dp[to];
    }
    dp[now]^=a[now];
}
void mainwork(int T){
    int k,n;
    scanf("%d%d",&n,&k);
    sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        sum^=a[i];
        dp[i]=0;
        G[i].clear();
    }
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        G[u].eb(v);
        G[v].eb(u);
    }
    dfs(1,0);
    if(sum==0){
        puts("YES");
        return;
    }else if(k==2){
        puts("NO");
        return;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=(dp[i]==sum);
    }
    puts(cnt>2?"YES":"NO");
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