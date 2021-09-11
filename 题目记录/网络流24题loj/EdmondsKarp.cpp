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
    int from,to,cap,flow,nxt;
    E (int u=0,int v=0,int c=0,int f=0,int n=-1):from(u),to(v),cap(c),flow(f),nxt(n){}

}edges[MAXE];
int tot,head[MAXN];
void Addedge(int u,int v,int cap){
    edges[tot]={u,v,cap,0,head[u]};
    head[u]=tot++;
    edges[tot]={v,u,0,0,head[v]};
    head[v]=tot++;
    
}
int n,m;
int a[MAXN],p[MAXN];
int bfs(int s,int t){
    int flow=0;
    while(1){
        for(int i=1;i<=n;i++){
            a[i]=0;
        }
        queue<int> q;
        q.push(s);
        a[s]=INF;
        while(!q.empty()){
            int now=q.front();q.pop();
            for(int i=head[now];~i;i=edges[i].nxt){
                E &e=edges[i];
                if(!a[e.to]&&e.cap>e.flow){
                    p[e.to]=i;
                    a[e.to]=min(a[now],e.cap-e.flow);
                    q.push(e.to);
                }
            }
            if(a[t])break;
        }
        if(!a[t])break;
        for(int now=t;now^s;now=edges[p[now]].from){
            edges[p[now]].flow+=a[t];
            edges[p[now]^1].flow-=a[t];
        }
        flow+=a[t];
    }
    return flow;
}
void mainwork(int T){
    int s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=n;i++)head[i]=-1;
    for(int i=1,u,v,c;i<=m;i++){
        scanf("%d%d%d",&u,&v,&c);
        Addedge(u,v,c);
    }
    int ans=bfs(s,t);
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