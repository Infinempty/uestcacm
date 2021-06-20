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

int sta[MAXN];
int vis[MAXN][MAXN];
vector<int> ans;
int nowidx=0,n;
void dfs(int now){
    ans.pb(now);
    for(int i=1;i<ans.size();i++){
        printf("%d%c",ans[i],i==ans.size()-1?'\n':'.');
    }

    nowidx++;
    for(int i=1;i<=n;i++){
        if(sta[nowidx]==i)dfs(i);
        else break;
    }
    ans.pop_back();

}
void mainwork(int T){
    scanf("%d",&n);
    ans.clear();
    nowidx=0;
    for(int i=1;i<=n;i++){
        scanf("%d",sta+i);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vis[i][j]=0;
        }
    }
    dfs(0);
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