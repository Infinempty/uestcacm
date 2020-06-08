#include<iostream>
#include<math.h>
#define ll long long
using namespace std;

/* 整除分块
	 对于i属于[1,n]
	 n除以i向下取整值相同的区间为
	 (i,n/(n/i))
	 求和  
	 for(int i=1;i<=n;i=j+1)
	{	
		j=n/(n/i);
		ans+=(j-i+1)*(n/i);
	}
	 */ 


ll sum(ll a1,ll n,ll d)
{
	ll an=a1+(n-1)*d;
	return (a1+an)*n/2;
}

int main()
{
	ll ans=0,n=0,k=0,temp=0,p=0,d=0;
	scanf("%lld %lld",&n,&k);
	p=k;
		
	for(ll i=1,j;i<=k&&i<=n;i=j+1)
	{
		j=k/(k/i);
		if(i==j)ans+=k%i;
		else if(n>i&&n<j)
		{
			ans+=sum(k%j+(j-n)*(k/j),n-i+1,k/j);
		}
		else ans+=sum(k%j,j-i+1,k/j);
	}
	if(n>k)ans+=(n-k)*k;
	cout<<ans;
}
