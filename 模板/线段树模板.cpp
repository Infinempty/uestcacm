#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define MAXN 1000000
struct Node
{	
	ll mx,mn,sum,lz_sum;
}tr[4*MAXN+10];
ll in[MAXN+10];
/*ll max(ll a,ll b)
{
	if(a>=b)return a;
	else return b;
}
ll min(ll a,ll b)
{
	if(a>=b)return b;
	else return a;
}*/
void update(int p,ll val,int l,int r)
{
	tr[p].sum+=(r-l+1)*val;
	tr[p].lz_sum+=val;
	tr[p].mn+=val;
	tr[p].mx+=val;
}
void push_down(int p,int lb,int rb)
{
	int mid=(lb+rb)/2;
	update(p*2,tr[p].lz_sum,lb,mid);
	update(p*2+1,tr[p].lz_sum,mid+1,rb);
	tr[p].lz_sum=0;
}
void build(int p,int l,int r)
{
	if(r==l)
	{
		tr[p].mn=tr[p].mx=tr[p].sum=in[l];
		tr[p].lz_sum=0;
		return;
	}
	build(p*2,l,(l+r)/2);
	build(p*2+1,(l+r)/2+1,r);
	tr[p].sum=tr[p*2].sum+tr[p*2+1].sum;
	tr[p].mx=max(tr[p*2].mx,tr[p*2+1].mx);
	tr[p].mn=min(tr[p*2].mn,tr[p*2+1].mn);
}
void change(ll val,int l,int r,int p,int lb,int rb)
{
	if(lb<=l&&rb>=r)
	{
		update(p,val,l,r);
		return; 
	}
	int mid=(l+r)/2;
	push_down(p,l,r);
	if(lb<=mid)change(val,l,mid,p*2,lb,rb);
	if(rb>=mid+1)change(val,mid+1,r,p*2+1,lb,rb);
	tr[p].sum=tr[p*2].sum+tr[p*2+1].sum;
	tr[p].mx=max(tr[p*2].mx,tr[p*2+1].mx);
	tr[p].mn=min(tr[p*2].mn,tr[p*2+1].mn);
}
ll query_sum(int p,int l,int r,int lb,int rb)
{
	if(lb<=l&&rb>=r)return tr[p].sum;
	ll temp=0;
	push_down(p,l,r);
	int mid=(l+r)/2;
	if(lb<=mid)temp+=query_sum(p*2,l,mid,lb,rb);
	if(rb>=mid+1)temp+=query_sum(p*2+1,mid+1,r,lb,rb);
	return temp;
}
ll query_max(int p,int l,int r,int lb,int rb)
{
	if(lb<=l&&rb>=r)return tr[p].mx;
	push_down(p,l,r);
	int mid=(l+r)/2;
	ll temp=0;
	if(lb<=mid&&rb>mid)temp=max(query_max(p*2,l,mid,lb,rb),query_max(p*2+1,mid+1,r,lb,rb));
	else if(lb>mid)temp=query_max(p*2+1,mid+1,r,lb,rb);
	else if(rb<=mid)temp=query_max(p*2,l,mid,lb,rb);
	return temp;
}
ll query_min(int p,int l,int r,int lb,int rb)
{
	if(lb<=l&&rb>=r)return tr[p].mn;
	push_down(p,l,r);
	ll temp=0;
	int mid=(l+r)/2;
	if(lb<=mid&&rb>mid)temp=min(query_min(p*2,l,mid,lb,rb),query_min(p*2+1,mid+1,r,lb,rb));
	else if(lb>mid)temp=query_min(p*2+1,mid+1,r,lb,rb);
	else if(rb<=mid)temp=query_min(p*2,l,mid,lb,rb);
	return temp;
}
ll query_limit(int p,int l,int r,int lb,int rb)
{
	ll maxn=0,minn=0;
	maxn=query_max(p,l,r,lb,rb);
	minn=query_min(p,l,r,lb,rb);
	return maxn-minn;
}
int main()
{
	memset(in,0,sizeof(in));
	int N=0,Q=0,o=0,l=0,r=0;
	ll val=0,ans=0;
	scanf("%d %d",&N,&Q);
	//for(int i=1;i<=N;i++)scanf("%lld",&in[i]);
	build(1,1,N);
	for(int i=1;i<=Q;i++)
	{
		scanf("%d",&o);
		switch(o)
		{
			case 1:
				scanf("%d %d %lld",&l,&r,&val);
				change(val,1,N,1,l,r);
				break;
			case 2:
				scanf("%d %d",&l,&r);
				ans=query_sum(1,1,N,l,r);
				printf("%lld\n",ans);
				break;
			case 3:
				scanf("%d %d",&l,&r);
				ans=query_limit(1,1,N,l,r);
				printf("%lld\n",ans);
				break;
		}
	}
	return 0;
}
