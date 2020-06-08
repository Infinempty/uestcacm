#include<bits/stdc++.h>
#define ll long long
#define MAX 1e18
using namespace std;
vector<pair<ll,ll> > v[200050];
ll a[200050]; 
ll dis[200050];
int vis[200050];
priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<pair<ll,ll> > >q;
int n,m;
void dij(){
	//这里2*w的意思是一个来回，具体情况需具体分析 
	ll now=0,v1=0,w=0;
	q.push({0,0});
	while(!q.empty()){
		now=q.top().second;q.pop();
		if(vis[now]){
			continue;
		}
		vis[now]=1;
		for(int i=0;i<v[now].size();i++){
			v1=v[now][i].first;
			w=v[now][i].second;
			if(w==0){
				q.push({dis[v1],v1});
				continue;
			}
			if(dis[now]+2*w<dis[v1]){
				dis[v1]=dis[now]+2*w;
				q.push({dis[v1],v1});
			}
		}
	}
	return ;
}

void solve(){
	ll x,y;
	ll v1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&x,&y,&v1);
		v[x].push_back({y,v1});
		v[y].push_back({x,v1});
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		dis[i]=a[i];
		v[0].push_back({i,0});
	}
	dij();
	for(int i=1;i<=n;i++){
		printf("%lld ",dis[i]);
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
