#include<bits/stdc++.h>
using namespace std;
const int N=100000+200,M=300000+200;
int n,m,t=1,Last[M*2],dfn[N],low[N],bridge[N],cnt,tot;
struct edge{int ver,next;}e[M*2];
pair < int,int > ans[N];
inline void insert(int x,int y)
{
	e[++t].ver=y;e[t].next=Last[x];Last[x]=t;
}
inline void input(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		insert(x,y);
		insert(y,x);
	}
}
inline void Tarjan(int x,int inedge)
{
	dfn[x]=low[x]=++cnt;
	for(int i=Last[x];i;i=e[i].next)
	{
		int y=e[i].ver;
		if(!dfn[y])
		{
			Tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x])
				bridge[i]=bridge[i^1]=true;
		}
		else if(i!=(inedge^1))
			low[x]=min(low[x],dfn[y]);
	}
}
int main(void)
{
	input();
	for(int i=1;i<=n;i++)
		if(!dfn[i])Tarjan(i,0);
	for(int i=2;i<t;i+=2)
		if(bridge[i])
		{
			if(e[i].ver>e[i^1].ver)swap(e[i].ver,e[i^1].ver);
			ans[++tot]=make_pair(e[i].ver,e[i^1].ver);
		}
	sort(ans+1,ans+tot+1);
	for(int i=1;i<=tot;i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}