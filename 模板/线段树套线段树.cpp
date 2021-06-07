//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2")

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
const int MAXE=10000050;
const int MAXN=1050;
const int bk_sz=3420;


int a[MAXN][MAXN];
int n,m;

struct segment{
	int seg_id;
	int tr[MAXN<<2],tag[MAXN<<2];
	
	void init(int _id){this->seg_id=_id;}
	inline void pushup(int id){tr[id]=tr[lc(id)]+tr[rc(id)];}
	
	void build(int id,int lb,int rb){
		if(lb>=rb){
			tr[id]=a[seg_id][lb];
			tag[id]=0;
			return;
		}
		int mid=(lb+rb)>>1;
		build(lc(id),lb,mid);
		build(rc(id),mid+1,rb);
		pushup(id);
	}
	void modify(int id,int l,int r,int lb,int rb,int val){
		tr[id]+=(r-l+1)*val;
		if(l==lb&&r==rb){
			tag[id]+=val;
			return;
		}
		int mid=(lb+rb)>>1;
		if(r<=mid)modify(lc(id),l,r,lb,mid,val);
		else if(l>mid)modify(rc(id),l,r,mid+1,rb,val);
		else{
			modify(lc(id),l,mid,lb,mid,val);
			modify(rc(id),mid+1,r,mid+1,rb,val);
		}
	}
	int query(int id,int l,int r,int lb,int rb,int add=0){
		if(l==lb&&r==rb){
			return tr[id]+add*(rb-lb+1);
		}
		add+=tag[id];
		int mid=(lb+rb)>>1;
		if(r<=mid)return query(lc(id),l,r,lb,mid,add);
		else if(l>mid)return query(rc(id),l,r,mid+1,rb,add);
		else return query(lc(id),l,mid,lb,mid,add)+query(rc(id),mid+1,r,mid+1,rb,add);
	}
}seg[MAXN<<2],tag[MAXN<<2];

void pushup(int now,int id,int ilb,int irb){
	seg[now].tr[id]=seg[lc(now)].tr[id]+seg[rc(now)].tr[id];
	if(ilb>=irb)return;
	int mid=(ilb+irb)>>1;
	pushup(now,lc(id),ilb,mid);
	pushup(now,rc(id),mid+1,irb);
}

void build(int now,int wlb,int wrb){
	if(wlb>=wrb){
		seg[now].init(wlb);
		seg[now].build(1,1,m);
		return;
	}
	int mid=(wlb+wrb)>>1;
	build(lc(now),wlb,mid);
	build(rc(now),mid+1,wrb);
	pushup(now,1,1,m);
}
void update(int now,int x1,int x2,int y1,int y2,int val,int wlb,int wrb){
	seg[now].modify(1,y1,y2,1,m,val*(x2-x1+1));
	if(x1==wlb&&x2==wrb){
		tag[now].modify(1,y1,y2,1,m,val);
		return;
	}
	int mid=(wlb+wrb)>>1;
	if(x2<=mid)update(lc(now),x1,x2,y1,y2,val,wlb,mid);
	else if(x1>mid)update(rc(now),x1,x2,y1,y2,val,mid+1,wrb);
	else {
		update(lc(now),x1,mid,y1,y2,val,wlb,mid);
		update(rc(now),mid+1,x2,y1,y2,val,mid+1,wrb);
	}
	//pushup(now,1,1,m);
}
int get_ans(int now,int x1,int x2,int y1,int y2,int wlb,int wrb,int add=0){
	if(x1==wlb&&x2==wrb){
		return seg[now].query(1,y1,y2,1,m)+add*(wrb-wlb+1);
	}
	int mid=(wlb+wrb)>>1;
	add+=tag[now].query(1,y1,y2,1,m);
	if(x2<=mid)return get_ans(lc(now),x1,x2,y1,y2,wlb,mid,add);
	else if(x1>mid)return get_ans(rc(now),x1,x2,y1,y2,mid+1,wrb,add);
	else return get_ans(lc(now),x1,mid,y1,y2,wlb,mid,add)+get_ans(rc(now),mid+1,x2,y1,y2,mid+1,wrb,add);
}


void mainwork(int T){
	int q;
	
	// break int !!! may > 2^31
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%lld",a[i]+j);
		}
	}
	build(1,1,n);
	for(int i=1,x1,x2,y1,y2,opt,k;i<=q;i++){
		scanf("%lld%lld%lld%lld%lld",&opt,&x1,&y1,&x2,&y2);
		if(max(x1,x2)==x1)swap(x1,x2);
		if(max(y1,y2)==y1)swap(y1,y2);
		if(opt==1){
			scanf("%lld",&k);
			update(1,x1,x2,y1,y2,k,1,n);
		}else{
			printf("%lld\n",get_ans(1,x1,x2,y1,y2,1,n));
		}
	}
	
	
}
signed main(){
	//IOS;
	#ifndef ONLINE_JUDGE
	freopen("Ranulx.in","r",stdin);
	freopen("Ranulx.out","w",stdout);
	#endif
	int t=1;
	//scanf("%d",&t);
	//prework(MAXN-50);
	for(int i=1;i<=t;i++){
		mainwork(i);
	}
}

