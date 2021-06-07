#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define maxn 200005
using namespace std;
//using namespace __gnu_pbds;
const double PI=acos(-1.0);
const double eps=1e-6;
int n,m,s,t,cnt,head[maxn],dep[maxn];
struct Edge
{
	int to,nxt,w;
}edge[maxn];
queue<int>q;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
void addedge(int u,int v,int w)
{
    edge[cnt].w=w;
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt++;
}
bool bfs()
{
	memset(dep,0,sizeof(dep));
	q.push(s);
	dep[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int k=head[u];k!=-1;k=edge[k].nxt){
			int v=edge[k].to;
			if(edge[k].w && !dep[v]){
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[t];
}
int dfs(int u,int flow)
{
	if(u==t) return flow;
	int rflow=0;
	for(int k=head[u];k!=-1 && flow;k=edge[k].nxt){
		int v=edge[k].to;
		if(edge[k].w && dep[v]==dep[u]+1){
			int mi=dfs(v,min(edge[k].w,flow));
			edge[k].w-=mi;
			edge[k^1].w+=mi;
			flow-=mi;
			rflow+=mi;
		}
	}
	if(!rflow) dep[u]=0;
	return rflow;
}
int Dinic()
{
    int ans=0;
    while(bfs()) ans+=dfs(s,INFI);
    return ans;
}
int main()
{
    memset(head,-1,sizeof(head));
	n=read(),m=read(),s=read(),t=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,0);
	}
	printf("%d\n",Dinic());
	return 0;
}
