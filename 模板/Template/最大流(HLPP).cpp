#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define INFI 2147483640
#define maxn 10010
#define maxm 2000020
int cnt=1,head[maxn];
int n,m,s,t,inque[maxn];
int e[maxn],h[maxn],cnth[maxn];//e:预流,h:高度
struct Node
{
    int v;
    int val;
    int nxt;
}edge[2*maxm];
struct cmp
{
    inline bool operator () (int a,int b) const
    {
        return h[a]<h[b];
    }
};
std::priority_queue<int,std::vector<int>,cmp> q;
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
inline void addedge(int u,int v,int val)
{
    edge[++cnt].v=v;
    edge[cnt].val=val;
    edge[cnt].nxt=head[u];
    head[u]=cnt;
    return;
}
bool bfs()
{
    for(register int i=0;i<maxn;++i) h[i]=INFI;
    h[t]=0;
    std::queue<int> qu;
    qu.push(t);
    while(!qu.empty()){
        int u=qu.front();
        qu.pop();
        for(int i=head[u];i;i=edge[i].nxt){
            int d=edge[i].v;
            if(edge[i^1].val && h[d]>h[u]+1){
                h[d]=h[u]+1;
                qu.push(d);
            }
        }
    }
    return h[s]!=INFI;
}
inline void push_(int u)
{
    for(register int i=head[u];i;i=edge[i].nxt){
        int d=edge[i].v;
        if(edge[i].val && h[d]+1==h[u]){
            int mi=std::min(edge[i].val,e[u]);
            edge[i].val-=mi;
            edge[i^1].val+=mi;
            e[u]-=mi;
            e[d]+=mi;
            if(!inque[d] && d!=t && d!=s){
                q.push(d);
                inque[d]=1;
            }
            if(!e[u]) break;
        }
    }
    return;
}
inline void relabel(int u)
{
    h[u]=INFI;
    for(register int i=head[u];i;i=edge[i].nxt){
        int d=edge[i].v;
        if(edge[i].val && h[u]>h[d]+1) h[u]=h[d]+1;
    }
    return;
}
int HLPP()
{
    if(!bfs()) return 0;
    h[s]=n;
    for(register int i=1;i<=n;i++) if(h[i]!=INFI) cnth[h[i]]++;
    for(register int i=head[s];i;i=edge[i].nxt){
        int d=edge[i].v;
        int mi=edge[i].val;
        if(mi){
            e[s]-=mi;
            e[d]+=mi;
            edge[i].val-=mi;
            edge[i^1].val+=mi;
            if(d!=t && inque[d]==0 && d!=s){
                q.push(d);
                inque[d]=1;
            }
        }
    }
    while(!q.empty()){
        int u=q.top();
        inque[u]=0;
        q.pop();
        push_(u);
        if(e[u]){
            cnth[h[u]]--;
            if(!cnth[h[u]]){
                for(register int i=1;i<=n;i++){
                    if(i!=s && i!=t && h[i]>h[u] && h[i]<n+1){
                        cnth[h[i]]--;
                        h[i]=n+1;
                        cnth[h[i]]++;
                    }
                }
            }
            relabel(u);
            cnth[h[u]]++;
            q.push(u);
            inque[u]=1;
        }
    }
    return e[t];
}
int main()
{
    n=read(),m=read(),s=read(),t=read();
    for(register int i=1;i<=m;i++){
        int u,v,val;
        u=read();
        v=read();
        val=read();
        addedge(u,v,val);
        addedge(v,u,0);
    }
    printf("%d",HLPP());
    return 0;
}
