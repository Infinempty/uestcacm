#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
long long in[500050],temp[500050];
long long ans=0;
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
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>in[i];
	MergeSort(1,n);
	for(int i=1;i<=n;i++)cout<<in[i]<<" ";
	cout<<endl<<ans;
}
