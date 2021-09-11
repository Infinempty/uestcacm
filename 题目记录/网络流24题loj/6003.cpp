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
const int MAXN=1000050;
const int bk_sz=3420;
mt19937 rnd(114514);

vector<int> G;
bool vis[MAXN];
vector<int> ans[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    G.push_back(1);
    for(int i=1;i<=1000;i++){
        vis[i*i]=1;
    }
    int fin=1;
    ans[1].pb(1);
    for(int i=2;G.size()<=n;i++){
        bool ok=0;
        for(int j=0;j<G.size();j++){
            if(vis[i+G[j]]){
                G[j]=i;
                ans[j+1].pb(i);
                ok=1;
                fin++;
                break;
            }
        }
        if(!ok){
            if(G.size()==n)break;
            else {
                G.pb(i);
                ans[G.size()].pb(i);
                fin++;
            }
        }
    }
    printf("%d\n",fin);
    for(int i=1;i<=n;i++){
        for(int j=0;j<ans[i].size();j++){
            printf("%d%c",ans[i][j],j==ans[i].size()-1?'\n':' ');
        }
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