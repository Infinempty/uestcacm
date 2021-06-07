void sieve()
{
    for(int i=2;i<=maxn;i++){
        mu[1]=1;
        phi[1]=1;
        if(!vis[i]) pri[++tot]=i,mu[i]=-1,phi[i]=i-1;
        for(int j=1;j<=tot && i*pri[j]<=maxn;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
                mu[i*pri[j]]=0;
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
            mu[i*pri[j]]=-mu[i];
            phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
    }
    return;
}