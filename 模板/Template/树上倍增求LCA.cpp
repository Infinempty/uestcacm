#pragma GCC optimize (3)
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000010;
int n,m,root;
struct Node
{
    int u;
    int v;
    int next;
}edge[MAXN];
int cnt=1;
int head[MAXN];
int deep[MAXN];
int f[MAXN][20];
void read(int & x)
{
    char c=getchar();
	x=0;
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
}
void edge_add(int x,int y)
{
    edge[cnt].u=x;
    edge[cnt].v=y;
    edge[cnt].next=head[x];
    head[x]=cnt++;
}
void dfs(int now)
{
    for(int i=head[now];i!=-1;i=edge[i].next){
        int n=edge[i].v;
        if(!deep[n]){
            deep[n]=deep[now]+1;
            f[n][0]=now;
            dfs(n);
        }
    }
}
void init()
{
    for(int i=1;i<=19;i++) for(int j=1;j<=n;j++) f[j][i]=f[f[j][i-1]][i-1];
}
int LCA(int x,int y)
{
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=19;i>=0;i--){
        if(deep[f[x][i]]>=deep[y])
        x=f[x][i];
    }
    if(x==y) return y;
    for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
int main()
{
    read(n);
	read(m);
	read(root);
    for(int i=1;i<=n;i++) head[i]=-1;
    for(int i=1;i<=n-1;i++){
        int x,y;
        read(x);
		read(y);
        edge_add(x,y);
        edge_add(y,x);
    }
    deep[root]=1;
    dfs(root);
    init();
    for(int i=1;i<=m;i++){
        int x,y;
        read(x);
		read(y);
        printf("%d\n",LCA(x,y));
    }
    return 0;
}
