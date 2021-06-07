struct Edge
{
	int to,nxt,w;
}edge[2*maxn];
//记得视情况开二倍空间！！！
int cnt,head[maxn];//将head初始化为全-1
void addedge(int u,int v,int w)
{
    edge[cnt].w=w;
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
	return;
}
for(int k=head[u];k!=-1;k=edge[k].nxt) int v=edge[k].to;//如何遍历u的邻接结点v