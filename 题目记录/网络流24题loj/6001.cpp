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
    int from,to,nxt,cap,flow;
}edges[MAXN];
int head[MAXN],tot;
void addedge(int u,int v,int cap){
    edges[tot]={u,v,head[u],cap,0};
    head[u]=tot++;
    edges[tot]={v,u,head[v],0,0};
    head[v]=tot++;
}
int cur[MAXN],dep[MAXN];
bool vis[MAXN];
int n,s,t;
bool bfs(){
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    queue<int> q;
    q.push(s);
    vis[s]=1;dep[s]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=head[now];~i;i=edges[i].nxt){
            E &e=edges[i];
            if(!vis[e.to]&&e.cap>e.flow){
                vis[e.to]=1;
                q.push(e.to);
                dep[e.to]=dep[now]+1;
            }
        }
    }
    return vis[t];
}
int dfs(int now,int a){
    if(now==t||!a)return a;
    int flow=0,f;
    for(int &i=cur[now];~i;i=edges[i].nxt){
        E &e=edges[i];
        if(dep[e.to]==dep[now]+1&&(f=dfs(e.to,min(a,e.cap-e.flow)))>0){
            flow+=f;a-=f;
            e.flow+=f;
            edges[i^1].flow-=f;
            if(!a)break;
        }
    }
    return flow;
}
int maxflow(){
    int ans=0;
    while(bfs()){
        for(int i=1;i<=n;i++)cur[i]=head[i];
        ans+=dfs(s,INF);
    }
    return ans;
}

inline bool read(int &x){
    x=0;
    int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return ch!='\n'&&ch!='\r';
}

//1-m 实验 m+1-m+n 仪器
// m+n+1 源点 m+n+2汇点

void mainwork(int T){
    int nn,m;
    read(m);read(nn);
    n=nn+m+2;
    s=nn+m+1,t=nn+m+2;
    int ans=0;
    for(int i=1;i<=n;i++)head[i]=-1;
    for(int i=1,tmp;i<=m;i++){
        read(tmp);
        ans+=tmp;
        addedge(s,i,tmp);
        while(1){
            bool ok=read(tmp);
            addedge(i,m+tmp,INF);
            if(!ok)break;
        }
    }
    for(int i=1,tmp;i<=nn;i++){
        read(tmp);
        addedge(m+i,t,tmp);
    }
    // for(int i=0;i<tot;i++){
    //     printf("%d %d %d %d\n",i,edges[i].from,edges[i].to,edges[i].nxt);
    // }
    ans-=maxflow();
    bool pre=0;
    for(int i=1;i<=m;i++){
        if(vis[i]){
            if(pre){
                printf(" ");
            }else pre=1;
            printf("%d",i);
        }
    }
    puts("");
    pre=0;
    for(int i=1;i<=nn;i++){
        if(vis[i+m]){
            if(pre){
                printf(" ");
            }else pre=1;
            printf("%d",i);
        }
    }
    puts("");
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