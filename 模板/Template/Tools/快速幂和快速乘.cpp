ll fpow(ll a,ll b,ll p)
{
    ll res=1;
    while(b){
        if(b&1) res=(res*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return res;
}
ll fmul(ll a,ll b,ll p){//快速乘,计算(a*b)%p 
    ll ret=0;
    while(b){
        if(b&1) ret=(ret+a)%p;
        a=(a+a)%p;
        b>>=1;
    }
    return ret;
}