#include<cstdio>
#include<algorithm>
#include<cstring>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
bool vis[10001];
int cnt,n,k,Ans,Root,tot,Tsiz,siz[10001],wt[10001],h[10001],nxt[20001],to[20001],w[20001],arr[10001];
inline void ins(int x,int y,int z)
{
	nxt[++tot]=h[x];
	to[tot]=y;
	w[tot]=z;
	h[x]=tot;
	return;
}
void GetRoot(int u,int f)
{
    siz[u]=1; 
    wt[u]=0;
    eF(i,u) if(to[i]!=f&&!vis[to[i]]) GetRoot(to[i],u),siz[u]+=siz[to[i]],wt[u]=max(wt[u],siz[to[i]]);
    wt[u]=max(wt[u],Tsiz-siz[u]);
    if(wt[Root]>wt[u]) Root=u;
    return;
}
void Dfs(int u,int D,int f)
{
    arr[++cnt]=D;
    eF(i,u) if(to[i]!=f && !vis[to[i]]) Dfs(to[i],D+w[i],u);
}
int calc(int u,int D)
{
    cnt=0; 
    Dfs(u,D,0); 
    int l=1,r=cnt,sum=0;
    sort(arr+1,arr+cnt+1);
    for(;;++l){
        while(r && arr[l]+arr[r]>k) --r;
        if(r<l) break;
        sum+=r-l+1;
    }
    return sum;
}
void DFS(int u)
{
    Ans+=calc(u,0); 
    vis[u]=1;
    eF(i,u) if(!vis[to[i]]){
        Ans-=calc(to[i],w[i]);
        Root=0,Tsiz=siz[to[i]],GetRoot(to[i],0);
        DFS(Root);
    }
    return;
}
int main()
{
    int x,y,z;
    while(~scanf("%d%d",&n,&k) && n && k){
        tot=Ans=0; 
        memset(vis,0,sizeof vis); 
        memset(h,0,sizeof h);
        F(i,2,n) scanf("%d%d%d",&x,&y,&z),ins(x,y,z),ins(y,x,z);
        wt[0]=INF; 
        Tsiz=n; 
        GetRoot(1,0);
        DFS(Root);
        printf("%d\n",Ans-n);
    }
    return 0;
}