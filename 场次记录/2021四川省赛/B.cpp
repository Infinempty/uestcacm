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
vector<int> G[MAXN];
int cnt[MAXN];
int ans[MAXN];
void mainwork(int T){
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=k;i++){
        G[i].clear();
        cnt[i]=0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        ans[i]=0;
        G[a[i]].eb(i);
    }
    for(int i=1;i<=k;i++){
        if(G[i].size()&1){
            for(int j=0;j<G[i].size();j++){
                if(j&1){
                    ans[G[i][j]]=(m/n+1)/2;
                }else{
                    ans[G[i][j]]=m/n/2;
                }
            }
            if(m/n%2)cnt[i]=1;
        }else{
            for(int j=0;j<G[i].size();j++){
                if(j&1){
                    ans[G[i][j]]=m/n;
                }
            }
        }
    }
    for(int i=1;i<=m%n;i++){
        if(cnt[a[i]]){
            cnt[a[i]]=0;
            ans[i]++;
        }else{
            cnt[a[i]]=1;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d",ans[i]);
        if(i<n)printf(" ");
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