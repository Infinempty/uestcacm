bool vis[maxn];
ll tot,pri[maxn];
ll f[maxn],low[maxn];
void sieve()
{
    vis[1]=low[1]=1;
    f[1]=1;
    for(ll i=2;i<=maxn-1;i++){
        if(!vis[i]) low[i]=pri[++tot]=i,f[i]=i-2;
        for(ll j=1;j<=tot && i*pri[j]<=maxn-1;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
                low[i*pri[j]]=low[i]*pri[j];
                if(low[i]==i) f[i*pri[j]]=i/pri[j]*(pri[j]-1)*(pri[j]-1);
                else f[i*pri[j]]=f[i/low[i]]*f[low[i]*pri[j]];
                break;
            }
            low[i*pri[j]]=pri[j];
            f[i*pri[j]]=f[i]*f[pri[j]];
        }
    }
}
//f[]