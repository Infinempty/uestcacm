#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define MAXN 1000000
int N;
struct Node{	
	int mx;
}tr[8*MAXN+10];
int in[2*MAXN+10];
void build(int p,int l,int r){
	//建树 
	if(r==l)
	{
		tr[p].mx=in[l];
		return;
	}
	build(p<<1,l,(l+r)>>1);
	build(p<<1|1,((l+r)>>1)+1,r);
	tr[p].mx=max(tr[p<<1].mx,tr[p<<1|1].mx);
}
void change(ll val,int l,int r,int p,int t){
	//值的改变  目标区间[lb,rb],节点编号为p，操作区间为[l,r] ，改变值为val 
	if(l==r&&l==t){
		in[l]-=val;
		tr[p].mx-=val;
		return;
	}
	if(l==r&&l!=t)
		return;
	int mid=(l+r)>>1;
	if(t<=mid)change(val,l,mid,p<<1,t);
	else if(t>=mid+1)change(val,mid+1,r,(p<<1|1),t);
	tr[p].mx=max(tr[p<<1].mx,tr[p<<1|1].mx);
}
ll query_max(int p,int l,int r,int lb,int rb,int m){
	if(l==r){
		if(in[l]<m)return -1;
		else return l;
	}
	if(l>r)return -1;
	if(lb<=l&&rb>=r&&tr[p].mx<m)
		return -1;//[l,r]是操作区间 [lb,rb]是目标区间 
	int mid=(l+r)>>1;
	int temp=0;
	if(lb<=mid&&rb>mid){
		temp=query_max(p<<1,l,mid,lb,rb,m);
		if(temp==-1)temp=query_max(p<<1|1,mid+1,r,lb,rb,m);
	}
	else if(lb>mid)temp=query_max(p<<1|1,mid+1,r,lb,rb,m);
	else if(rb<=mid)temp=query_max(p<<1,l,mid,lb,rb,m);
	return temp;
}
void solve(){
	int t,l,cnt=0,o,ans,index,tmp;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&in[i]);
	build(1,1,N);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d %d",&index,&o);
		o=max(0,o-cnt);
		index++;
		tmp=query_max(1,1,N,index,N,o);
		if(tmp==-1){
			tmp=query_max(1,1,N,1,index,o);
			if(tmp!=-1)ans=tmp+N-index;
			else ans=tmp;
		}else{
			ans=tmp-index;
		}
		printf("%d\n",ans);
		if(tmp!=-1)change(in[tmp]+1,1,N,1,tmp);
		cnt++;
		//for(int i=1;i<=N;i++)cout<<in[i]<<" "<<endl;
	}
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
