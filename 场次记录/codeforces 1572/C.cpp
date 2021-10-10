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
const int MAXN=5050;
const int bk_sz=3420;
mt19937 rnd(114514);

int a[MAXN];
int dp[MAXN][MAXN];
int pre[MAXN],pos[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        pos[i]=0;
    }
    int t=unique(a+1,a+n+1)-a-1;
    n=t;
    for(int i=1;i<=n;i++){
        if(pos[a[i]]){
            pre[i]=pos[a[i]];
        }
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=INF;
        }
    }
    for(int i=1;i<=n;i++)dp[i][i]=0;
    for(int i=1;i<n;i++)dp[i][i+1]=1;
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            dp[i][j]=min(dp[i][j-1]+1,dp[i+1][j]+1);
            if(a[i]==a[j]){
                dp[i][j]=min(dp[i][j],dp[i+1][j-1]+1);
                for(int k=pre[j];k>i;k=pre[k]){
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]);
                }
            }else{
                for(int k=pre[j];k>i;k=pre[k]){
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k][j]+1);
                }
            }
        }
    }
    printf("%d\n",dp[1][n]);
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