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
int fa[MAXN],son[MAXN][2],val[MAXN],res[MAXN];
bool tag[MAXN];
inline bool ident(int x,int f){return son[f][1]==x;}
inline bool ntroot(int x){return son[fa[x]][0]==x||son[fa[x]][1]==x;}
inline void update(int now){res[now]=res[son[now][0]]^res[son[now][1]]^val[now];}
inline void connect(int x,int f,int s){
	fa[x]=f;
	son[f][s]=x;
}
void reverse(int now){
	tag[now]^=1;
	swap(son[now][0],son[now][1]);
}
void pushdown(int now){
	if(!now||!tag[now])return;
	int ls=son[now][0],rs=son[now][1];
	if(ls)reverse(ls);
	if(rs)reverse(rs);
	tag[now]=0;
}
void rotate(int x){
	int f=fa[x],ff=fa[f],k=ident(x,f);
	connect(son[x][k^1],f,k);
	fa[x]=ff;
	if(ntroot(f))son[ff][ident(f,ff)]=x;
	connect(f,x,k^1);
	update(f),update(x);
}
void pushall(int x){
	if(ntroot(x))pushall(fa[x]);
	pushdown(x);
}
void splaying(int x){
	pushall(x);
	while(ntroot(x)){
		int f=fa[x],ff=fa[f];
		if(ntroot(f)){
			if(ident(f,ff)^ident(x,f))rotate(x);
			else rotate(f);
		}
		rotate(x);
	}
}
void access(int x){
	for(int y=0;x;y=x,x=fa[x]){
		splaying(x);
		son[x][1]=y;
		update(x);
	}
}
void mkroot(int x){
	access(x);
	splaying(x);
	reverse(x);
}
int findroot(int x){
	access(x);
	splaying(x);
	while(son[x][0]){
		pushdown(x);
		x=son[x][0];
	}
	splaying(x);
	return x;
}
void link(int x,int y){
	mkroot(x);
	if(findroot(y)==x)return;
	fa[x]=y;
}
void cut(int x,int y){
	mkroot(x);
	if(findroot(y)!=x||fa[y]!=x||son[y][0])return;
	fa[y]=son[x][1]=0;
	update(x);
}
void split(int x,int y){
	mkroot(x);
	access(y);
	splaying(y);
}
void mainwork(int T){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",val+i);
		res[i]=val[i];
	}
	int x,y,opt;
	while(m--){
		scanf("%d%d%d",&opt,&x,&y);
		switch(opt){
		case 0:
			split(x,y);
			printf("%d\n",res[y]);
			break;
		case 1:
			link(x,y);
			break;
		case 2:
			cut(x,y);
			break;
		case 3:
			splaying(x);
			val[x]=y;
			update(x);
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
