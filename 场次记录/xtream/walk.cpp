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
struct E{
    int from,to,col;
    ll val;
};
struct node{
    int now,col;
    ll dis;
    bool operator <(const node &rhs)const{
        return dis^rhs.dis?dis<rhs.dis:now<rhs.now;
    }
    bool operator >(const node &rhs)const{
        return rhs<*this;
    }
};
vector<E> G[MAXN];
int work(char s){
    return s-'a'+1;
}
ll dis[MAXN][6];
bool vis[MAXN][6];
void dij(int s,int n,ll c){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            dis[i][j]=LINF;
            vis[i][j]=0;
        }
    }
    dis[s][1]=0;
    //for(int i=1;i<=5;i++)dis[s][i]=0;
    priority_queue<node,vector<node>,greater<node> >q;
    q.push({s,1,0});
    while(!q.empty()){
        node now=q.top();q.pop();
        if(vis[now.now][now.col])continue;
        vis[now.now][now.col]=1;
        for(auto e:G[now.now]){
            ll cost=dis[now.now][now.col]+e.val+(now.col==e.col?0:c);
            if(dis[e.to][e.col]>cost){
                dis[e.to][e.col]=cost;
                q.push({e.to,e.col,dis[e.to][e.col]});
            }
        }
    }
}
ll getmin(int n){
    ll ans=LINF;
    for(int i=1;i<=5;i++){
        ans=min(ans,dis[n][i]);
    }
    return ans;
}
void mainwork(int T){
    int n,m;
    ll k;
    scanf("%d%d%lld",&n,&m,&k);
    char opt[10];
    for(int i=1;i<=n;i++){
        G[i].clear();
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        scanf("%s",opt);
        int c=work(opt[0]);
        G[u].push_back({u,v,c,w});
        G[v].push_back({v,u,c,w});
    }
    dij(1,n,LINF);
    if(getmin(n)<=k){
        puts("relaxing");
        return;
    }
    dij(1,n,1);
    if(getmin(n)>k){
        puts("impossible");
        return;
    }
    int l=1,r=1e9;
    while(l<r){
        int mid=(l+r+1)>>1;
        dij(1,n,mid);
        if(getmin(n)>k)r=mid-1;
        else l=mid;
    }
    printf("%d\n",l);

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