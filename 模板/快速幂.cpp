#include<bits/stdc++.h>
#define MOD 10000
using namespace std; 
ll mpow(ll a,ll n)
{
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
