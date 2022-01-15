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

vector<pair<ll,int> >G[MAXN];
bool vis[MAXN];
ll dis[MAXN];
int pre[MAXN];
void dij(int s,int n,int idx){
    for(int i=1;i<=n;i++){
        vis[i]=0;
        dis[i]=LINF;
    }
    dis[s]=0;
    //vis[s]=1;
    priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >q;
    q.push(mkp(0,s));
    while(!q.empty()){
        int now=q.top().second;q.pop();
        if(vis[now])continue;
        vis[now]=1;
        for(auto i:G[now]){
            ll w=i.first;int to=i.second;
            if(to==idx)continue;
            if(dis[to]>dis[now]+w){
                dis[to]=dis[now]+w;
                q.push(mkp(dis[to],to));
            }
        }
    }
}
void mainwork(int T){
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++){
        int u,v;ll w;
        scanf("%d%d%lld",&u,&v,&w);
        G[u].eb(mkp(w,v));
        G[v].eb(mkp(w,u));
    }
    ll ans=-1;
    int idx;
    for(int i=1;i<=n;i++){
        if(i==s||i==t)continue;
        dij(s,n,i);
        // for(int i=1;i<=n;i++){
        //     printf("%lld ",dis[i]);
        // }
        //puts("");
        if(dis[t]!=LINF&&dis[t]>ans){
            ans=dis[t];
            idx=i;
        }
    }
    if(ans==-1)puts("-1");
    else printf("%d\n",idx);
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