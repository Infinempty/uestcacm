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
 
const ll LINF=1e18;
const ll MOD=1e9+7;
const int INF=0x3f3f3f3f;
const int MAXN=200050;
//35000

int tot,root;
int fa[MAXN],val[MAXN],son[MAXN][2],cnt[MAXN],sz[MAXN],tag[MAXN];
inline bool ident(int x,int f){return son[f][1]==x;}
inline void update(int now){sz[now]=sz[son[now][0]]+sz[son[now][1]]+cnt[now];}
void connect(int x,int f,int s){
	fa[x]=f;
	son[f][s]=x;
}
void pushdown(int now){
	if(!tag[now]||!now)return;
	tag[now]=0;
	tag[son[now][0]]^=1;
	tag[son[now][1]]^=1;
	swap(son[now][0],son[now][1]);
	return;
}
void rotate(int x){
	//only rotate will break strcuture of balance tree
	int f=fa[x],ff=fa[fa[x]],k=ident(x,f);
	pushdown(f);pushdown(x);
	connect(son[x][k^1],f,k);
	connect(x,ff,ident(f,ff));
	connect(f,x,k^1);
	update(f);update(x);
}
void splaying(int x,int top){
	if(!top)root=x;
	while(fa[x]!=top){
		int f=fa[x],ff=fa[f];
		if(ff!=top){
			if(ident(f,ff)^ident(x,f))rotate(x);
			else rotate(f);	
		}
		rotate(x);
	}
}
void newnode(int &now,int in,int f){
	val[now=++tot]=in;
	fa[now]=f;
	sz[now]=cnt[now]=1;
}
void delnode(int x){
	splaying(x,0);
	if(cnt[x]>1)sz[x]--,cnt[x]--;
	else if(son[x][1]){
		int now=son[x][1];
		while(son[now][0])now=son[now][0];
		splaying(now,x);
		connect(son[x][0],now,0);
		root=now;
		fa[now]=0;
		update(root);
	}
	else root=son[x][0],fa[root]=0;
}
void insert(int in,int &now,int f){
	//写if加大括号是好习惯，没事别学别人一逗到底
	if(!now)newnode(now,in,f),splaying(now,0);
	else if(in<val[now])insert(in,son[now][0],now);
	else if(in>val[now])insert(in,son[now][1],now);
	else cnt[now]++,sz[now]++,splaying(now,0);
}
void remove(int in,int now){
	if(in==val[now])delnode(now);
	else if(in<val[now])remove(in,son[now][0]);
	else remove(in,son[now][1]);
}
int getrank(int num){
	int now=root,rank=1;
	while(now){
		pushdown(now);
		if(val[now]==num){
			rank+=sz[son[now][0]];
			splaying(now,0);
			break;
		}
		if(num<=val[now]){
			now=son[now][0];
		}else {
			rank+=sz[son[now][0]]+cnt[now];
			now=son[now][1];
		}
	}
	return rank;
}
int getnum(int rank){
	int now=root;
	while(now){
		pushdown(now);
		int lz=sz[son[now][0]];
		if(lz+1<=rank&&rank<=lz+cnt[now]){
			splaying(now,0);
			break;
		}else if(rank<=lz){
			now=son[now][0];
		}else{
			rank-=lz+cnt[now];
			now=son[now][1];
		}
	}
	return now;
}
void dfs(int now){
	if(!now)return;
	pushdown(now);
	dfs(son[now][0]);
	if(now!=1&&now!=2)printf("%d ",now-2);
	dfs(son[now][1]);
}
void mainwork(int T){
	int n,m;
	scanf("%d%d",&n,&m);
	insert(INF,root,0);insert(-INF,root,0);
	for(int i=1;i<=n;i++){
		insert(i,root,0);
	}
	int l,r,lpos,rpos;
	while(m--){
		scanf("%d%d",&l,&r);
		lpos=getnum(l);
		rpos=getnum(r+2);
		splaying(lpos,0);
		splaying(rpos,root);
		tag[son[son[root][1]][0]]^=1;
	}
	dfs(root);
	
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
