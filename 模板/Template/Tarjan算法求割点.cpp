#include<bits/stdc++.h>
#define maxn 100010
using namespace std;
struct edge
{
    int nxt,mark;
}pre[2*maxn];
int n,m,idx,cnt,tot;
int head[maxn],dfn[maxn],low[maxn];
bool cut[100010];
void add(int x,int y)
{
    pre[++cnt].nxt=y;
    pre[cnt].mark=head[x];
    head[x]=cnt;
}
void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++idx;
    int child=0;
    for(int i=head[u];i!=0;i=pre[i].mark){
        int nx=pre[i].nxt;
        if(!dfn[nx]){
            tarjan(nx,fa);
            low[u]=min(low[u],low[nx]);
            if(low[nx]>=dfn[u]&&u!=fa) cut[u]=1;
            if(u==fa) child++;
        }
        low[u]=min(low[u],dfn[nx]);
    }
    if(child>=2&&u==fa) cut[u]=1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=n;i++) if(dfn[i]==0) tarjan(i,i);
    for(int i=1;i<=n;i++) if(cut[i]) tot++;
    printf("%d\n",tot);
    for(int i=1;i<=n;i++) if(cut[i]) printf("%d ",i);
    return 0;
}
