#define ll long long
ll Euler(ll n)
{
	if(n==1LL) return 1LL;
    ll ans=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}