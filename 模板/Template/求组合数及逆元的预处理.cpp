void init()
{
    inv[1]=1LL;
    for(int i=2;i<maxn;i++) inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod;
    F[0]=Finv[0]=1LL;
    for(int i=1;i<maxn;i++){
        F[i]=F[i-1]*1LL*i%mod;
        Finv[i]=Finv[i-1]*1LL*inv[i]%mod;
    }
}
int comb(int n,int m)
{
    if(m<0 || m>n) return 0;
    return F[n]*1LL*Finv[n-m]%mod*Finv[m]%mod;
}