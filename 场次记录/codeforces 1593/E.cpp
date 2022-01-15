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
const int MAXN=400050;
const int bk_sz=3420;
mt19937 rnd(114514);

vector<int> G[MAXN];
int deg[MAXN],cnt[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    int t;
    scanf("%d",&t);
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        G[u].eb(v);
        G[v].eb(u);
        deg[u]++;
        deg[v]++;
    }
    queue<pair<int,int> > q;
    for(int i=1;i<=n;i++){
        if(deg[i]<=1){
            q.push(mkp(i,1));
            cnt[1]++;
        }
    }
    while(!q.empty()){
        int now=q.front().first,tmp=q.front().second;q.pop();
        for(auto to:G[now]){
            deg[to]--;
            if(deg[to]==1){
                q.push(mkp(to,tmp+1));
                cnt[tmp+1]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cnt[i]+=cnt[i-1];
    }
    t=min(t,n);
    printf("%d\n",n-cnt[t]);
    for(int i=1;i<=n;i++){
        G[i].clear();
        deg[i]=cnt[i]=0;
    }
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