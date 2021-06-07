#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define maxn 1000005
using namespace std;
//using namespace __gnu_pbds;
const double PI=acos(-1.0);
const double eps=1e-6;
bool vis[maxn];
int cnt,dis[maxn],head[maxn];//head赋值为-1
struct Edge
{
	int to,nxt,w;
}edge[2*maxn];
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
void Dijkstra(int s)
{
    for(int i=0;i<maxn;i++) dis[i]=INFI;
    priority_queue<PII,vector<PII >,greater<> > q;
    dis[s]=0;
    q.push(make_pair(dis[s],s));
    while(!q.empty()){
        PII tmp=q.top();
        q.pop();
        if(vis[tmp.second]) continue;
        vis[tmp.second]=1;
        int u=tmp.second;
        //if(u==t) return;
        for(int k=head[u];k!=-1;k=edge[k].nxt){
            int &v=edge[k].to;
            if(dis[v]>dis[u]+edge[k].w){
                dis[v]=dis[u]+edge[k].w;
                if(!vis[v]) q.push(make_pair(dis[v],v));
            }
        }
    }
    return;
}
int main()
{
    int n,m,s;
    memset(head,-1,sizeof(head));
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++) printf("%d ",dis[i]);
    return 0;
}
