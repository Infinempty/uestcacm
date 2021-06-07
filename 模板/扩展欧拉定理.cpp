#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll euler(ll n) {
    ll ans=n;
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}
ll mpow(ll a,ll n,ll MOD)
{
	if(a==1||n==0)return 1;
	ll ans=1;
	a%=MOD;
	while(n!=0)
	{
		if(n&1)ans=(ans*a)%MOD;
		n>>=1;
		a=(a*a)%MOD;
	}
	return ans%MOD;
}
//a^b mod MOD
ll EXeuler(ll a,string &in,ll MOD){
	ll phi,b=0;
	bool flag=0;
	phi=euler(MOD);
	for(int i=0;i<in.size();i++){
		b*=10;
		b+=in[i]-'0';
		if(b>=phi)flag=1;
		b%=phi;
	}
	if(flag)b+=phi;
	return mpow(a,b,MOD);
}
