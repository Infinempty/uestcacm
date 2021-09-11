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

struct E{
    int from,to,nxt;
}edges[MAXE];
int head[MAXN],tot;
void addedge(int u,int v){
    edges[++tot].from=u;
    edges[tot].to=v;
    edges[tot].nxt=head[u];
    head[u]=tot;
}
int pre[MAXN],low[MAXN],sccno[MAXN],cyc[MAXN];
int dfs_clock,scc_cnt;
stack<int> sk;
void init(int n){
    dfs_clock=scc_cnt=0;
    while(!sk.empty())sk.pop();
    for(int i=1;i<=n;i++){
        pre[i]=low[i]=sccno[i]=0;
        head[i]=-1;
        cyc[i]=0;
    }
    tot=0;
}
void dfs(int now){
    pre[now]=low[now]=++dfs_clock;
    sk.push(now);
    for(int i=head[now];~i;i=edges[i].nxt){
        int to=edges[i].to;
        if(!pre[to]){
            dfs(to);
            low[now]=min(low[now],low[to]);
        }else if(!sccno[to]){
            low[now]=min(low[now],pre[to]);
        }
    }
    if(low[now]==pre[now]){
        scc_cnt++;
        while(1){
            int x=sk.top();sk.pop();
            sccno[x]=scc_cnt;
            if(x==now)break;
        }
    }
}

vector<int> G[MAXN];
int ans[MAXN],deg[MAXN];
void newgraph(int n){
    for(int i=1;i<=n;i++){
        ans[i]=0;
        deg[i]=0;
        G[i].clear();
    }
    for(int i=1;i<=tot;i++){
        int u=edges[i].from,v=edges[i].to;
        if(sccno[u]==sccno[v]&&sccno[u])ans[sccno[u]]=-1;
        else if(sccno[u]&&sccno[v]){
            G[sccno[u]].eb(sccno[v]);
            deg[sccno[v]]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(cyc[i]&&sccno[i]){
            ans[sccno[i]]=-1;
        }
    }
    for(int i=1;i<=scc_cnt;i++){
        if(deg[i]>1&&ans[i]!=-1)ans[i]=2;
        else if(ans[i]!=-1)ans[i]=1;
    }
    queue<int> q;
    q.push(sccno[1]);
    while(!q.empty()){
        int now=q.front();q.pop();
        for(auto to:G[now]){
            if(ans[now]==-1){
                ans[to]=-1;
            }else if(ans[now]==2&&ans[to]!=-1){
                ans[to]=2;
            }
            deg[to]--;
            if(!deg[to])q.push(to);
        }
    }

}

void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    init(n);
    for(int i=1,u,v;i<=m;i++){
        scanf("%d%d",&u,&v);
        if(u==v){
            cyc[u]=1;
            continue;
        }
        addedge(u,v);
    }
    dfs(1);
    newgraph(n);
    // for(int i=1;i<=n;i++){
    //     printf("%d %d %d %d\n",pre[i],low[i],sccno[i],cyc[i]);
    // }
    sccno[0]=0;
    for(int i=1;i<=n;i++){
        printf("%d ",ans[sccno[i]]);
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