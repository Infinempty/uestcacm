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
int minn[MAXN][MAXN];
vector<int> pos;
void mainwork(int T){
    int n;
    scanf("%d",&n);
    pos.eb(0);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        if(a[i])pos.eb(i);
    }
    memset(minn,0x3f,sizeof(minn));
    for(int i=0;i<=n;i++)minn[0][i]=0;
    for(int i=1;i<pos.size();i++){
        //dp[i][j] 表示把第i个人移动到j最小花费
        //dp[i][j]=min dp[i-1][1到j-1]最小+abs(pos[i]-j)
        //不能移动到a[i]为1的位置
        
        for(int j=i;j<=n;j++){
            minn[i][j]=min(minn[i][j-1],minn[i][j]);
            if(!a[j])minn[i][j]=min(minn[i][j],minn[i-1][j-1]+abs(pos[i]-j));
        }
    }
    int ans=minn[pos.size()-1][n];
    printf("%d\n",ans);

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