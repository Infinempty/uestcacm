```c++
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define ull unsigned long long
#define lll __int128
#define pr pair<int,int>
#define N 100005
#define INF 2147483647
using namespace std;
mt19937 mrand(random_device{}());
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll mul(ll a,ll b,ll p){return (lll)a*b%p;}
ll qpow(ll a, ll b,ll mod) { ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) { if (b & 1)res = mul(res,a,mod); a = mul(a,a,mod); }return res; }
bool Witness(ll a,ll n){//a能否作为n为合数的证据
    ll t=0,u=n-1;
    while(u%2==0){
        u/=2;
        t++;
    }
    ll y=qpow(a,u,n),x;
    for(ll i=1;i<=t;i++){
        x=y;
        y=mul(y,y,n);
        if(y==1&&x!=1&&x!=n-1)return 1;
    }
    return y!=1;
}
//	Miller-Rabin primality test(Deterministic)
//  Strong Probable-prime Base （ SPRP ）
//	{ 2, 7, 61 } for 2^32
//	{ 2, 3, 7, 61, 24251 } for 1e16 (except 46856248255981)
//	{ 2, 325, 9375, 28178, 450775, 9780504, 1795265022 } for 2^64
bool Miller_Rabin(ll n){
    if(n%2==0)return n==2;
    if(n<128)return (0X816D129A64B4CB6E >> (n / 2)) & 1;
    const ll L[7]={ 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
    for(ll p:L) if(Witness(p,n))return 0;
    return 1;
}
ll Pollard_Rho(ll n){
    uniform_int_distribution<ll> dist(1, n-1);
    ll x=0,y=0,t=1,q=1,c=dist(mrand);
    for(int k=2;;k<<=1,y=x,q=1){
        for(int i=1;i<=k;i++){
            x=((lll)mul(x,x,n)+c)%n;
            q=mul(q,llabs(x-y),n);
            if(!(i&127)&&(t=gcd(q,n)>1))break;
        }
        t=t>1?t:gcd(q,n);
        if(t>1)break;
    }
    return t;
}
void PR(vector<ll>&res,ll n){
    if(Miller_Rabin(n))return res.push_back(n);
    ll p=n;
    while(p>=n)p=Pollard_Rho(n);
    PR(res,p);
    PR(res,n/p);
}
int main() {
    int t;
    cin>>t;
    while(t--){
        ll n;
        vector<ll>fac;
        cin>>n;
        PR(fac,n);
        if(fac.back()==n)cout<<"Prime\n";
        else {
            ll res=0;
            for(auto i:fac)res=max(res,i);
            cout<<res<<'\n';
        }
    }
	return 0;
}
```

