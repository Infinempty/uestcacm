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
const ll MOD=2e18;
const int INF=0x3f3f3f3f;
const int MAXN=100050;

int ls[MAXN],rs[MAXN],val[MAXN],sz[MAXN],cnt[MAXN];
int tot,root;
void newnode(int &now,int in){
	now=++tot;
	val[tot]=in;
	sz[tot]=1;
	cnt[tot]=1;
}
void update(int now){
	sz[now]=sz[ls[now]]+sz[rs[now]]+cnt[now];
}
int rrot(int now){
	int l=ls[now];
	ls[now]=rs[l];
	rs[l]=now;
	update(now);update(l);
	return l;
}
int lrot(int now){
	int r=rs[now];
	rs[now]=ls[r];
	ls[r]=now;
	update(now);update(r);
	return r;
}
void splaying(int x,int &y){
	if(x==y)return;
	if(x==ls[y]){
		y=rrot(y);
		return;
	}else if(x==rs[y]){
		y=lrot(y);
		return;
	}
	if(val[x]<val[y]){
		if(val[x]<val[ls[y]]){
			splaying(x,ls[ls[y]]);
			y=rrot(y);y=rrot(y);
		}else{
			splaying(x,rs[ls[y]]);
			ls[y]=lrot(ls[y]);y=rrot(y);
		}
	}else{
		if(val[x]>val[rs[y]]){
			splaying(x,rs[rs[y]]);
			y=lrot(y);y=lrot(y);
		}else{
			splaying(x,ls[rs[y]]);
			rs[y]=rrot(rs[y]);y=lrot(y);
		}
	}
}
void insert(int &now,int in){
	if(!now)newnode(now,in),splaying(now,root);
	else if(in<val[now])insert(ls[now],in);
	else if(in>val[now])insert(rs[now],in);
	else sz[now]++,cnt[now]++,splaying(now,root);
}
void remove_node(int now){
	splaying(now,root);
	if(cnt[root]>1){
		cnt[root]--;
		sz[root]--;
		return;
	}
	if(!rs[root]){
		root=ls[root];
	}else{
		int nxt=rs[root];
		while(ls[nxt])nxt=ls[nxt];
		splaying(nxt,rs[root]);
		ls[rs[root]]=ls[root];
		root=rs[root];
		update(root);
	}
}
void remove(int now,int in){
	if(val[now]==in)remove_node(now);
	else if(in<val[now])remove(ls[now],in);
	else if(in>val[now])remove(rs[now],in);
}
int getrank(int num){
	int now=root,rank=1;
	while(now){
		if(val[now]==num){
			rank+=sz[ls[now]];
			splaying(now,root);
			break;
		}
		if(num<val[now]){
			now=ls[now];
		}else{
			rank+=sz[ls[now]]+cnt[now];
			now=rs[now];
		}
	}
	return rank;
}
int getnum(int rank){
	int now=root;
	while(now){
		if(sz[ls[now]]+1<=rank&&sz[ls[now]]+cnt[now]>=rank){
			splaying(now,root);
			break;
		}else if(sz[ls[now]]>=rank){
			now=ls[now];
		}else{
			rank-=sz[ls[now]]+cnt[now];
			now=rs[now];
		}
	}
	return val[now];
}
void mainwork(int T){
	int q,opt,x;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&opt,&x);
		switch(opt){
		case 1:
			insert(root,x);
			break;
		case 2:
			remove(root,x);
			break;
		case 3:
			printf("%d\n",getrank(x));
			break;
		case 4:
			printf("%d\n",getnum(x));
			break;
		case 5:
			printf("%d\n",getnum(getrank(x)-1));
			break;
		case 6:
			printf("%d\n",getnum(getrank(x+1)));
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
