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
const int MAXN=50;
const int bk_sz=3420;
mt19937 rnd(114514);

char s[MAXN];
int dp[MAXN][MAXN][MAXN][MAXN];
struct N{
    int i,j,k,l;
}pre[MAXN][MAXN][MAXN][MAXN];
char fin[MAXN];
// 第i个数，红色j，红色模a是k，黑色模b是l
void mainwork(int T){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",s+1);
    memset(dp,0,sizeof(dp));
    dp[1][0][0][(s[1]-'0')%b]=1;
    pre[1][0][0][(s[1]-'0')%b]={0,0,0,0};
    dp[1][1][(s[1]-'0')%a][0]=1;
    pre[1][1][(s[1]-'0')%a][0]={0,0,0,0};
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<a;k++){
                for(int l=0;l<b;l++){
                    if(!dp[i][j][k][l])continue;
                    int now=s[i+1]-'0';
                    now = ((l*10)+now)%b;
                    dp[i+1][j][k][now]=1;
                    pre[i+1][j][k][now]={i,j,k,l};
                    now = ((k*10)+s[i+1]-'0')%a;
                    dp[i+1][j+1][now][l]=1;
                    pre[i+1][j+1][now][l]={i,j,k,l};
                }
            }
        }
    }
    int ans=INF,idx=-1;
    for(int i=1;i<n;i++){
        if(dp[n][i][0][0]&&ans>abs(n-2*i)){
            ans=n-2*i;
            idx=i;
        }
    }
    if(idx==-1){
        puts("-1");
        return;
    }
    //printf("%d\n",ans);
    N now={n,idx,0,0};
    while(now.i){
        fin[now.i]=(pre[now.i][now.j][now.k][now.l].j==now.j?'B':'R');
        now=pre[now.i][now.j][now.k][now.l];
    }
    fin[n+1]=0;
    puts(fin+1);
    
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