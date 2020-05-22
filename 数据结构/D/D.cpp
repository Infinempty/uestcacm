#include<bits/stdc++.h>
using namespace std; 
#define MAXN 1000000
struct Node
{	
	int mx,mn,lz_sum;
}tr[8*MAXN+200];
int in[2*MAXN+50];
char cord[2*MAXN+50];
char a[2*MAXN+50];
void update(int p,int val,int l,int r)
{
	if(l==r)in[l]+=val;
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
		tr[p].mn=tr[p].mx=in[l];
		tr[p].lz_sum=0;
		return;
	}
	build(p*2,l,(l+r)/2);
	build(p*2+1,(l+r)/2+1,r);
	tr[p].mx=max(tr[p*2].mx,tr[p*2+1].mx);
	tr[p].mn=min(tr[p*2].mn,tr[p*2+1].mn);
}
void change(int val,int l,int r,int p,int lb,int rb)
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
	tr[p].mx=max(tr[p*2].mx,tr[p*2+1].mx);
	tr[p].mn=min(tr[p*2].mn,tr[p*2+1].mn);
}
int query_max(int p,int l,int r,int lb,int rb)
{
	if(lb<=l&&rb>=r)return tr[p].mx;
	push_down(p,l,r);
	int mid=(l+r)/2;
	int temp=0;
	if(lb<=mid&&rb>mid)temp=max(query_max(p*2,l,mid,lb,rb),query_max(p*2+1,mid+1,r,lb,rb));
	else if(lb>mid)temp=query_max(p*2+1,mid+1,r,lb,rb);
	else if(rb<=mid)temp=query_max(p*2,l,mid,lb,rb);
	return temp;
}
int query_min(int p,int l,int r,int lb,int rb)
{
	if(lb<=l&&rb>=r)return tr[p].mn;
	push_down(p,l,r);
	int temp=0;
	int mid=(l+r)/2;
	if(lb<=mid&&rb>mid)temp=min(query_min(p*2,l,mid,lb,rb),query_min(p*2+1,mid+1,r,lb,rb));
	else if(lb>mid)temp=query_min(p*2+1,mid+1,r,lb,rb);
	else if(rb<=mid)temp=query_min(p*2,l,mid,lb,rb);
	return temp;
}
void solve(){
	int index,N;
	scanf("%d",&N);
	index=N+1;
	scanf("%s",&a);
	build(1,1,2*N+10);
	for(int i=0;i<N;i++){
		if(a[i]=='L')index--;
		else if(a[i]=='R')index++;
		else if(a[i]=='('){
			if(cord[index]==')'){
				change(2,1,2*N+10,1,index,2*N+10);
			}else if(cord[index]!='('){
				change(1,1,2*N+10,1,index,2*N+10);
			}
			cord[index]='(';
		}else if(a[i]==')'){
			if(cord[index]=='('){
				change(-2,1,2*N+10,1,index,2*N+10);
			}else if(cord[index]!=')'){
				change(-1,1,2*N+10,1,index,2*N+10);
			}
			cord[index]=')';
		}else{
			if(cord[index]=='('){
				change(-1,1,2*N+10,1,index,2*N+10);
			}else if(cord[index]==')'){
				change(1,1,2*N+10,1,index,2*N+10);
			}
			cord[index]=a[i];
		}
		if(tr[1].mn<0||query_max(1,1,2*N+10,2*N+10,2*N+10)!=0){
			cout<<"-1 ";
		}else {
			cout<<tr[1].mx<<" ";
		}
	}
	cout<<"\n";
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t=1;
	//scanf("%d",&t);
	while(t--){
		solve();
	}
}
