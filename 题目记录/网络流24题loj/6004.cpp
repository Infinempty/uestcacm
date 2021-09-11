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
void addedge(int u,int v,int cap){
    edges[tot]={u,v,head[u],cap,0};
    head[u]=tot++;
    edges[tot]={v,u,head[v],0,0};
    head[v]=tot++;
}
int n,s,t;
void bfs(){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    queue<int>q;
    q.push(t);
    vis[t]=1;dep[t]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=head[now];~i;i=edges[i].nxt){
            E &e=edges[i^1];
            if(!vis[e.from]&&e.cap){
                vis[e.from]=1;
                dep[e.from]=dep[now]+1;
                q.push(e.from);
            }
        }
    }
}
int augment(){
    int a=INF;
    for(int now=t;now^s;now=edges[p[now]].from){
        E &e=edges[p[now]];
        a=min(a,e.cap-e.flow);
    }
    for(int now=t;now^s;now=edges[p[now]].from){
        edges[p[now]].flow+=a;
        edges[p[now]^1].flow-=a;
    }
    return a;
}
int maxflow(){
    int flow=0;
    for(int i=0;i<=n;i++){
        cur[i]=head[i];
        gap[i]=0;
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
                E &e=edges[i];
                if(e.cap>e.flow){
                    minn=min(minn,dep[e.to]);
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
void mainwork(int T){
    int m,nn;
    scanf("%d%d",&m,&nn);
    n=m+nn+2,s=m+nn+1,t=m+nn+2;
    int sum=0;
    for(int i=1;i<=n;i++)head[i]=-1;
    for(int i=1,tmp;i<=m;i++){
        scanf("%d",&tmp);
        addedge(s,i,tmp);
        sum+=tmp;
    }
    for(int i=1,tmp;i<=nn;i++){
        scanf("%d",&tmp);
        addedge(i+m,t,tmp);
    }
    for(int i=1;i<=m;i++){
        for(int j=m+1;j<=m+nn;j++){
            addedge(i,j,1);
        }
    }
    int ans=maxflow();
    if(sum>ans){
        puts("0");
        return;
    }
    puts("1");
    for(int i=1;i<=m;i++){
        for(int j=head[i];~j;j=edges[j].nxt){
            E &e=edges[j];
            if(e.cap==1&&e.flow==1){
                printf("%d ",e.to-m);
            }
        }
        puts("");
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

