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

int head[MAXN];
struct E{
    int from,to,nxt;
    bool tag;
}edges[MAXE];
int tot;
void addedge(int u,int v){
    edges[++tot].from=u;
    edges[tot].to=v;
    edges[tot].nxt=head[u];
    edges[tot].tag=0;
    head[u]=tot;
}
int vis[MAXN];
int is_key[MAXN];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    tot=0;
    for(int i=1;i<=n;i++)head[i]=-1;
    for(int i=1,u,v;i<=m;i++){
        scanf("%d%d",&u,&v);
        addedge(u,v);
        //addedge(v,u);
    }
    queue<int>q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=head[now];~i;i=edges[i].nxt){
            int to=edges[i].to;
            if(!vis[to]){
                vis[to]=vis[now]+1;
                is_key[i]=1;
                q.push(to);
            }
        }
    }
    int dis=vis[n]-1;
    for(int i=1;i<=m;i++){
        if(!is_key[i]){
            printf("%d\n",dis);
            continue;
        }
        edges[i].tag=1;
        for(int i=1;i<=n;i++)vis[i]=0;
        q.push(1);
        vis[1]=1;
        while(!q.empty()){
            int now=q.front();q.pop();
            for(int i=head[now];~i;i=edges[i].nxt){
                if(edges[i].tag)continue;
                int to=edges[i].to;
                if(!vis[to]){
                    vis[to]=vis[now]+1;
                    q.push(to);
                }
            }
        }
        edges[i].tag=0;
        printf("%d\n",vis[n]-1);
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