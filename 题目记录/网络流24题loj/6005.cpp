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


struct E{
    int from,to,nxt;
    int cap,flow;
}edges[MAXE];

int head[MAXN],tot;
int cur[MAXN],gap[MAXN],dep[MAXN],p[MAXN];
bool vis[MAXN];
void init(int n){
    for(int i=1;i<=n;i++){
        head[i]=-1;
    }
    tot=0;
}
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


int a[MAXN],dp[MAXN];
void mainwork(int T){
    int nn;
    scanf("%d",&nn);
    for(int i=1;i<=nn;i++){
        scanf("%d",a+i);
    }
    int maxx=1;
    for(int i=1;i<=nn;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]<=a[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        maxx=max(maxx,dp[i]);
    }
    printf("%d\n",maxx);
    if(maxx==1){
        printf("%d\n%d\n",nn,nn);
        return;
    }
    n=nn*2+2,s=nn*2+1,t=nn*2+2;
    init(n);
    //1-n 入点 n+1-2n 出点 s=2n+1,t=2n+2
    for(int i=1;i<=nn;i++){
        if(dp[i]==1)addedge(s,i,1);
        if(dp[i]==maxx)addedge(i+nn,t,1);
        addedge(i,i+nn,1);
        for(int j=1;j<i;j++){
            if(dp[j]+1==dp[i]&&a[j]<=a[i]){
                addedge(j+nn,i,1);
            }
        }
    }
    printf("%d\n",maxflow());
    /*这里是重置边流量&&修改边容量*/
    for(int i=0;i<tot;i++){
        edges[i].flow=0;
        if(edges[i].from==s)edges[i].cap=INF;
        if(edges[i].to==t)edges[i].cap=INF;
        if(edges[i].from+nn==edges[i].to)edges[i].cap=INF;
    }
    /*         end              */
    /*这里是重新建图*/
    // init(n);
    // for(int i=1;i<=nn;i++){
    //     if(dp[i]==1)addedge(s,i,INF);
    //     if(dp[i]==maxx)addedge(i+nn,t,INF);
    //     addedge(i,i+nn,INF);
    //     for(int j=1;j<i;j++){
    //         if(dp[j]+1==dp[i]&&a[j]<=a[i]){
    //             addedge(j+nn,i,1);
    //         }
    //     }
    // }
    printf("%d\n",maxflow());
    

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