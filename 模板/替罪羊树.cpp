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
const double alpha=0.75;

struct Node{
	int val,l,r;
	int sz,fact,cnt;
	bool exist;
}tr[MAXN];
int tot,root;
void newnode(int &now,int val){
	now=++tot;
	tr[now].exist=true;
	tr[now].fact=tr[now].sz=tr[now].cnt=1;
	tr[now].val=val;
}
bool imbalance(int now){
	if(1.0*max(tr[tr[now].l].sz,tr[tr[now].r].sz)>1.0*tr[now].sz*alpha
	 ||1.0*tr[now].fact<tr[now].sz*0.7)	return true;
	return false;
}
void dfs(int now,vector<int> &v){
	if(!now)return;
	dfs(tr[now].l,v);
	if(tr[now].exist){
		v.pb(now);
	}
	dfs(tr[now].r,v);
}
void push_up(int now){
	tr[now].sz=tr[tr[now].l].sz+tr[tr[now].r].sz+tr[now].cnt;
	tr[now].fact=tr[tr[now].l].fact+tr[tr[now].r].fact+tr[now].cnt;
}
void lift(int lb,int rb,int &now,vector<int> &v){
	if(lb==rb){
		now=v[lb];
		tr[now].l=tr[now].r=0;
		tr[now].sz=tr[now].fact=tr[now].cnt;
		return;
	}
	int mid=(lb+rb)>>1;
	now=v[mid];
	if(lb<mid)lift(lb,mid-1,tr[now].l,v);
	else tr[now].l=0;
	lift(mid+1,rb,tr[now].r,v);
	push_up(now);
	
}
void rebuild(int &now){
	vector<int> v;
	dfs(now,v);
	if(v.empty()){
		now=0;
		return;
	}
	lift(0,v.size()-1,now,v);
}
void update(int now,int end){
	if(!now)return;
	if(end==now)return;
	else if(tr[end].val<tr[now].val)
		update(tr[now].l,end);
	else update(tr[now].r,end);
	push_up(now);
}
void check(int &now,int end){
	if(now==end)return;
	if(imbalance(now)){
		rebuild(now);
		update(root,now);
		return;
	}
	if(tr[end].val<tr[now].val)check(tr[now].l,end);
	else check(tr[now].r,end);
}
void insert(int &now,int val){
	if(!now){
		newnode(now,val);
		check(root,now);
		return;
	}
	if(tr[now].val==val){
		tr[now].cnt++;
		tr[now].fact++;
		tr[now].sz++;
		tr[now].exist=true;
		return;
	}
	tr[now].sz++;tr[now].fact++;
	if(val<tr[now].val)insert(tr[now].l,val);
	else insert(tr[now].r,val);
}
void remove(int &now,int val){
	if(tr[now].exist&&tr[now].val==val){
		tr[now].cnt--;
		tr[now].fact--;
		if(tr[now].cnt==0){
			tr[now].exist=false;
		}
		check(root,now);
		return;
	}
	tr[now].fact--;
	if(val<tr[now].val)remove(tr[now].l,val);
	else remove(tr[now].r,val);
}
int getrank(int val){
	int now=root,rank=1;
	while(now){
		if(tr[now].val==val){
			rank+=tr[tr[now].l].fact;
			break;
		}else if(val<tr[now].val){
			now=tr[now].l;
		}else {
			rank+=tr[tr[now].l].fact+tr[now].cnt;
			now=tr[now].r;
		}
	}
	return rank;
}
int getval(int rank){
	int now=root;
	while(now){
		if(tr[now].exist&&tr[tr[now].l].fact+tr[now].exist<=rank&&tr[tr[now].l].fact+tr[now].cnt>=rank){
			break;
		}
		if(tr[tr[now].l].fact>=rank){
			now=tr[now].l;
		}else{
			rank-=tr[tr[now].l].fact+tr[now].cnt;
			now=tr[now].r;
		}
	}
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
				printf("%d\n",getval(getrank(val)-1));
				break;
			case 6:
				printf("%d\n",getval(getrank(val+1)));
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
