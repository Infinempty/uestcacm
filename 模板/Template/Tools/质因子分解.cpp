vector<pair<ll,ll> > factorize(ll n)
{
    vector<pair<ll,ll> > res;
    for(ll i=2;i*i<=n;i++){
        if(n%i) continue;
        res.emplace_back(i,0);
        while(n%i==0){
            n/=i;
            res.back().second++;
        }
    }
    if(n!=1) res.emplace_back(n,1);
    return res;
}