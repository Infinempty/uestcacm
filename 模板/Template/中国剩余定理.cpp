//n个方程：x=a[i](mod m[i])(0<=i<n)
ll CRT(int n,ll *a,ll *m)
{
    ll M=1,ret=0;
    for(int i=0;i<n;i++) M*=m[i];
    for(int i=0;i<n;i++){
        ll w=M/m[i];
        ret=(ret+w*inv(w,m[i])*a[i])%M;
    }
    return (ret+M)%M;
}