#include<bits/stdc++.h>
 
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define lc(x) ((x)<<1)
#define rc(x) (((x)<<1)|1)
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
 
const ll LINF=2e18;
const ll MOD=1e9+7;
const int INF=0x3f3f3f3f;
const int MAXN=200050;
mt19937 rnd(114514);

struct Node{
	int l,r;
	int val,key;
	int sz;
}tr[MAXN];
int tot,root;
int newnode(int val){
	tr[++tot].val=val;
	tr[tot].sz=1;
	tr[tot].key=rnd();
	return tot;
}
void update(int now){
	tr[now].sz=tr[tr[now].l].sz+tr[tr[now].r].sz+1;
	return;
}
void spilt(int now,int val,int &x,int &y){
	if(!now){
		x=y=0;
		return;
	}
	if(tr[now].val<=val){
		x=now;
		spilt(tr[now].r,val,tr[now].r,y);
	}else{
		y=now;
		spilt(tr[now].l,val,x,tr[now].l);
	}
	update(now);
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(tr[x].key>tr[y].key){
		tr[x].r=merge(tr[x].r,y);
		update(x);
		return x;
	}else{
		tr[y].l=merge(x,tr[y].l);
		update(y);
		return y;
	}
}
void insert(int &root,int val){
	int x,y;
	spilt(root,val,x,y);
	root=merge(merge(x,newnode(val)),y);
}
void remove(int &root,int val){
	int x,y,z;
	spilt(root,val,x,z);
	spilt(x,val-1,x,y);
	y=merge(tr[y].l,tr[y].r);
	root=merge(merge(x,y),z);
}
int getrank(int val){
	int x,y;
	spilt(root,val-1,x,y);
	int ans=tr[x].sz+1;
	root=merge(x,y);
	return ans;
}
int getval(int rank){
	int now=root;
	while(now){
		if(tr[tr[now].l].sz+1==rank){
			break;
		}
		if(tr[tr[now].l].sz>=rank){
			now=tr[now].l;
		}else{
			rank-=tr[tr[now].l].sz+1;
			now=tr[now].r;
		}
	}
	return tr[now].val;
}
int getpre(int val){
	int x,y;
	spilt(root,val-1,x,y);
	int now=x;
	while(tr[now].r){
		now=tr[now].r;
	}
	root=merge(x,y);
	return tr[now].val;
}
int getnxt(int val){
	int x,y;
	spilt(root,val,x,y);
	int now=y;
	while(tr[now].l){
		now=tr[now].l;
	}
	root=merge(x,y);
	return tr[now].val;
}

void mainwork(int T){
	int q;
	scanf("%d",&q);
	while(q--){
		int opt,val;
		scanf("%d%d",&opt,&val);
		switch (opt){
			case 1:
				insert(root,val);
				break;
			case 2:
				remove(root,val);
				break;
			case 3:
				printf("%d\n",getrank(val));
				break;
			case 4:
				printf("%d\n",getval(val));
				break;
			case 5:
				printf("%d\n",getpre(val));
				break;
			case 6:
				printf("%d\n",getnxt(val));
				break;
		}
	}
}
signed main(){
	//IOS;
	#ifndef ONLINE_JUDGE
	//freopen("./in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	#endif
	int t=1;
	//scanf("%d",&t);
	//prework();
	for(int i=1;i<=t;i++){
		mainwork(i);
	}
}
