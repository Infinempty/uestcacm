#include<bits/stdc++.h>
#define ll long long
struct LBase
{
    ll d[61];
    LBase()
    {
        memset(d,0,sizeof(d));
    }
    bool Insert(ll x)
    {
        for(int i=60;i>=0;i--){
            if(x&((ll)1<<i)){
                if(d[i]) x^=d[i];
                else{
                    d[i]=x;
                    break;
                }
            }
        }
        return x>0;
    }
    ll qmax()
    {
        ll x=0;
        for(int i=60;i>=0;i--) if(d[i]) if((x^d[i])>x) x^=d[i];
        return x;
    }
    void Merge(const LBase &a)
    {
        for(int i=60;i>=0;i--) if (a.d[i]) Insert(a.d[i]);
    }
}lb;