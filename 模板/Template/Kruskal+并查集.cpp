#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
int n,m,k,f[MAXN];
struct edge
{
    int u,v,value;
}myedge[MAXN*MAXN];
bool cmp(const edge& p1,const edge& p2)
{
    return p1.value<p2.value;
}
int Find(int x)
{
    return (f[x]==x) ? x : (f[x]=Find(f[x]));
}
int main()
{
    cin>>n>>m;
    int i,x,y,sum=0,counter=0,value;
    for(i=0;i<m;i++) scanf("%d%d%d",&myedge[i].u,&myedge[i].v,&myedge[i].value);
    for(i=0;i<n;i++) f[i]=i;
    sort(myedge,myedge+m,cmp);
    for(i=0;i<m;i++){
        value=myedge[i].value;
        x=Find(myedge[i].u);
        y=Find(myedge[i].v);
        if(x!=y) {
            sum+=value;
            f[y]=x;
            counter++;
            if(counter==n-1) break;
        }
    }
    printf("%d\n",sum);
    return 0;
}