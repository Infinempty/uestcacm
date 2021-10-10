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

const ll MOD=998244353;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXE=5000050;
const int MAXN=100050;
const int bk_sz=3420;
mt19937 rnd(114514);

ll sum[MAXN][10][10];
bool vis[MAXN][10];
int a[MAXN];
int n;
void dfs(int dep,int now){
    if(vis[dep][now])return;
    vis[dep][now]=1;
    int t=(now+a[dep])%10;
    int tt=(now*a[dep])%10;
    if(dep==n){
        sum[dep][now][t]++;
        sum[dep][now][tt]++;
        return;
    }
    dfs(dep+1,t);
    for(int i=0;i<10;i++){
        sum[dep][now][i]+=sum[dep+1][t][i];
        sum[dep][now][i]%=MOD;
    }
    dfs(dep+1,tt);
    for(int i=0;i<10;i++){
        sum[dep][now][i]+=sum[dep+1][tt][i];
        sum[dep][now][i]%=MOD;
    }
}

void mainwork(int T){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    dfs(2,a[1]);
    for(int i=0;i<10;i++){
        printf("%lld\n",sum[2][a[1]][i]);
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