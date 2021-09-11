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

struct E{
    int from,to,nxt;
    int cap,flow;
}edges[MAXE];

int head[MAXN],tot;
int cur[MAXN],gap[MAXN],dep[MAXN],p[MAXN];
bool vis[MAXN];
void addedge(int u,int v,int cap){
    edges[tot]={u,v,head[u],cap,0};
    head[u]=tot++;
    edges[tot]={v,u,head[v],0,0};
    head[v]=tot++;
}
int s,t,n;
void bfs(){
    for(int i=1;i<=n;i++)vis[i]=0;
    queue<int> q;
    q.push(t);
    vis[t]=1;
    dep[t]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=head[now];~i;i=edges[i].nxt){
            E &e=edges[i^1];
            if(!vis[e.from]&&e.cap>e.flow){
                dep[e.from]=dep[now]+1;
                vis[e.from]=1;
                q.push(e.from);
            }
        }
    }
}
int augment(){
    int now=t,a=INF;
    for(now;now!=s;now=edges[p[now]].from){
        E &e=edges[p[now]];
        a=min(a,e.cap-e.flow);
    }
    now=t;
    for(now;now^s;now=edges[p[now]].from){
        edges[p[now]].flow+=a;
        edges[p[now]^1].flow-=a;
    }
    return a;
}
int maxflow(){
    int flow=0;
    for(int i=0;i<=n;i++){
        gap[i]=0;
        cur[i]=head[i];
    }
    bfs();
    for(int i=1;i<=n;i++){
        gap[dep[i]]++;
    }
    int now=s;
    while(dep[s]<n){
        if(now==t){
            flow+=augment();
            now=s;
        }
        bool ok=0;
        for(int &i=cur[now];~i;i=edges[i].nxt){
            E &e=edges[i];
            if(dep[e.to]+1==dep[now]&&e.cap>e.flow){
                ok=1;
                p[e.to]=i;
                now=e.to;
                break;
            }
        }
        if(!ok){
            int minn=n-1;
            for(int i=head[now];~i;i=edges[i].nxt){
                if(edges[i].cap>edges[i].flow){
                    minn=min(minn,dep[edges[i].to]);
                }
            }
            if(--gap[dep[now]]==0)break;
            gap[dep[now]=minn+1]++;
            cur[now]=head[now];
            if(now^s)now=edges[p[now]].from;
        }
    }
    return flow;
}

int a[MAXN][MAXN];
inline int getid(int x,int y,int nn){
    return (x-1)*nn+y;
}
void mainwork(int T){
    int nn,mm;
    scanf("%d%d",&mm,&nn);
    n=nn*mm+2,s=nn*mm+1,t=nn*mm+2;
    for(int i=1;i<=n;i++)head[i]=-1;
    int ans=0;
    for(int i=1;i<=mm;i++){
        for(int j=1;j<=nn;j++){
            scanf("%d",&a[i][j]);
            ans+=a[i][j];
            if((i+j)&1){
                addedge(s,getid(i,j,nn),a[i][j]);
                if(i>1)addedge(getid(i,j,nn),getid(i-1,j,nn),INF);
                if(i<mm)addedge(getid(i,j,nn),getid(i+1,j,nn),INF);
                if(j>1)addedge(getid(i,j,nn),getid(i,j-1,nn),INF);
                if(j<nn)addedge(getid(i,j,nn),getid(i,j+1,nn),INF);
            }else addedge(getid(i,j,nn),t,a[i][j]);
        }
    }
    ans-=maxflow();
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