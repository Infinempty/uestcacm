#include<bits/stdc++.h>
#define ll long long
#define INF 1e14
using namespace std;
struct edge{
    ll u,v,w;
} e[20050];
ll pos=0;
ll pre[1050],minz[1050];
int vis[1050],id[1050];
ll zhuliu(int root,int n,int m){
    int u,v,cnt=0;
    ll ans=0;
    while(1){
        for(int i=1;i<=n;i++)minz[i]=INF;
        for(int i=1;i<=m;i++){
            u=e[i].u,v=e[i].v;
            if(u!=v&&e[i].w<minz[v]){
                minz[v]=e[i].w;
                pre[v]=u;
                if(u==root)pos=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(i!=root&&minz[i]==INF)return -1;
        }
        cnt=0;
        minz[root]=0;
        for(int i=1;i<=n;i++)vis[i]=id[i]=-1;
        for(int i=1;i<=n;i++){
            ans+=minz[i];
            v=i;
            while(vis[v]!=i&&id[v]==-1&&v!=root){
                vis[v]=i;
                v=pre[v];
            }
            if(id[v]==-1&&v!=root){
                id[v]=++cnt;
                for(u=pre[v];u!=v;u=pre[u]){
                    id[u]=cnt;
                }
            }
        }
        if(cnt==0)break;
        for(int i=1;i<=n;i++){
            if(id[i]==-1)id[i]=++cnt;
        }
        for(int i=1;i<=m;i++){
            u=e[i].u;v=e[i].v;
            e[i].u=id[u],e[i].v=id[v];
            if(id[u]!=id[v])e[i].w-=minz[v];
        }
        root=id[root];
        n=cnt;
    }
    return ans;
}


void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    ll sum=1,ans=0;
    for(int i=1;i<=m;i++){
        scanf("%lld %lld %lld",&e[i].u,&e[i].v,&e[i].w);
        sum+=e[i].w;
    }
    for(int i=m+1;i<=n+m;i++){
        e[i].u=n+1;
        e[i].v=i-m;
        e[i].w=sum;
    }
    ans=zhuliu(n+1,n+1,n+m);
    if(ans==-1||ans-sum>=sum)printf("-1");
    else printf("%lld %lld\n",ans-sum,pos-m);
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve(); 
    }
    
}
