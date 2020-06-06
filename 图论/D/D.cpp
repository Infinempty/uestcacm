#include<bits/stdc++.h>
#define ll long long
#define MAX 1e18
using namespace std;
struct Node{
	int nxt;
	double val;
	bool operator < (const Node& rhs) const {
		return val>rhs.val;
	}
};
vector<Node> v[5050];
queue<int> q;
bool vis[5050];
double dis[5050];
int n,cnt[5050];

bool SPFA(int s){
	dis[s]=0;
	q.push(s);
	double w=0;
	int now=0,v1=0;
	vis[s]=1;
	while(!q.empty()){
		now=q.front();
		q.pop();
		vis[now]=0;
		for(int i=0;i<v[now].size();i++){
			v1=v[now][i].nxt;
			w=v[now][i].val;
			if(dis[now]+w<dis[v1]){
				dis[v1]=dis[now]+w;
				if(!vis[v1]){
					q.push(v1);
					vis[v1]=1;
					if(++cnt[v1]>n){
						return false;
					}
				}
			}
		}
	}
	return true;
}
void solve(){
	int m,o,a,b;
	double k;
	Node tmp;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %lf",&o,&a,&b,&k);
		k=log(k);
		if(o==1){
			tmp.nxt=b;
			tmp.val=-1*k;
			v[a].push_back(tmp);
		}else if(o==2){
			tmp.nxt=a;
			tmp.val=k;
			v[b].push_back(tmp);
		}else{
			tmp.nxt=a;
			tmp.val=k;
			v[b].push_back(tmp);
			tmp.nxt=b;
			tmp.val*=-1;
			v[a].push_back(tmp);
		}
	} 
	tmp.val=0;
	for(int i=1;i<=n;i++){
		tmp.nxt=i;
		v[0].push_back(tmp);
		dis[n]=1e9;
	}
	if(SPFA(0))printf("DEDEDEDEDEDEDEDEDEDEDEDE");
	else printf("Delicious");
}

signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t=1;
	//scanf("%d",&t);
	while(t--){
		solve(); 
	}
	
}
