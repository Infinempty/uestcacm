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

map<int,int> visp;
pair<int,int> a[MAXN];
bool vis[MAXN];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    sort(a+1,a+m+1);
    visp[n]=1;
    for(int i=1,j=1;i<=m;i=j){
        while(a[i].first==a[j].first)j++;
        for(int k=i;k<j;k++){
            vis[k]=visp[a[k].second-1]||visp[a[k].second+1];
        }
        for(int k=i;k<j;k++){
            visp[a[k].second]=vis[k];
        }
    }
    int ans=0;
    for(auto i:visp){
        ans+=i.second;
    }
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