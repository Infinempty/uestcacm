#include<bits/stdc++.h>
#define ll long long
using namespace std; 
long long in[500050],temp[500050],a[200050];
long long ans=0;
ll gcd(int n,int m){
	if(n<m)swap(n,m);
	if(n%m==0)return m;
	n%=m;
	return gcd(m,n);
}
void MergeSort(int l,int r)
{
	if(l>=r)return;
	int mid=(l+r)/2;
	MergeSort(l,mid);
	MergeSort(mid+1,r);
	int ql=l,qr=mid+1;
	int i=1;
	while(ql<=mid&&qr<=r)
	{
		if(in[ql]<in[qr])temp[i++]=in[ql++];
		else 
		{
			temp[i++]=in[qr++];
			ans+=(mid-ql+1);
		}
	}
	while(ql<=mid)temp[i++]=in[ql++];
	while(qr<=r)temp[i++]=in[qr++];
	for(int t=l;t<=r;t++)in[t]=temp[t-l+1];
}
void solve(){
	ll n,b,tmp;
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]-=b;
		in[i]=in[i-1]+a[i];
		if(in[i]<=0)ans++;
	}
	ll sum=(n+1)*n/2;
	MergeSort(1,n);
	do{
		tmp=gcd(sum,ans);
		sum/=tmp;
		ans/=tmp;
	}while(tmp!=1);
	cout<<ans<<"/"<<sum;
	
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	
}
