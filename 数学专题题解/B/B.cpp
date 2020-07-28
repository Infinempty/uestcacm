#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mu(ll n){
	int v=1;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			n/=i;
			v=-v;
			if(n%i==0)return 0;
		}
	}
	if(n!=1)v=-v;
	return v;
}

void solve(int t){
	ll n;
	scanf("%lld",&n);
	printf("%d\n",mu(n));
}
int main()
{
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		solve(i);
	}
}