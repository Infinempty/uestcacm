#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define INFI 2147483647
using namespace std;
const int maxn=100010;
bool vis[maxn];
int n,m,s,t,x,y,z,f,num_edge,maxflow,mincost,dis[maxn],pre[maxn],last[maxn],flow[maxn],head[maxn];
struct Edge
{
	int to,nxt,flow,dis;
}edge[maxn];
queue<int> q;
void add_edge(int u,int v,int flow,int dis)
{
	edge[++num_edge].nxt=head[u];
	edge[num_edge].to=v;
	edge[num_edge].flow=flow;
	edge[num_edge].dis=dis;
	head[u]=num_edge;
}
bool spfa(int s,int t)
{
	for(int i=0;i<=maxn-1;i++) dis[i]=INFI;
	for(int i=0;i<=maxn-1;i++) flow[i]=INFI;
	memset(vis,0,sizeof(vis));
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	pre[t]=-1;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		vis[now]=0;
		for(int i=head[now];i!=-1;i=edge[i].nxt){
			if(edge[i].flow>0 && dis[edge[i].to]>dis[now]+edge[i].dis){
				dis[edge[i].to]=dis[now]+edge[i].dis;
				pre[edge[i].to]=now;
				last[edge[i].to]=i;
				flow[edge[i].to]=min(flow[now],edge[i].flow);
				if(!vis[edge[i].to]){
					vis[edge[i].to]=1;
					q.push(edge[i].to);
				}
			}
		}
	}
	return pre[t]!=-1;
}
void MCMF()
{
	while(spfa(s,t)){
		int now=t;
		maxflow+=flow[t];
		mincost+=flow[t]*dis[t];
		while(now!=s){
			edge[last[now]].flow-=flow[t];
			edge[last[now]^1].flow+=flow[t];
			now=pre[now];
		}
	}
}
int main()
{
	memset(head,-1,sizeof(head));
	num_edge=-1;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&x,&y,&z,&f);
		add_edge(x,y,z,f);
		add_edge(y,x,0,-f);
	}
	MCMF();
	printf("%d %d",maxflow,mincost);
	return 0;
}
