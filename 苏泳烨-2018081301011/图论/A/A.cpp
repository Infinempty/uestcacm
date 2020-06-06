#include<bits/stdc++.h>
#define ll long long
#define MAX 1e16
using namespace std;
vector<int> v1[500005],v2[500005];
queue <int> q;
int n;
ll a[500005],ans=0,sum=0;
ll ear[500005],lat[500005];
int sor[500005],deg[500005];
void MapSort(){
	int tmp=1;
	for(int i=1;i<=n;i++){
		if(!deg[i]){
			q.push(i);
		}
	}
	while(!q.empty()){
		for(int i=0;i<v1[q.front()].size();i++){
			deg[v1[q.front()][i]]--;
			if(!deg[v1[q.front()][i]])q.push(v1[q.front()][i]);
		}
		sor[tmp++]=q.front();
		q.pop();
	}
}
void key_path(){
	while(!q.empty())q.pop();
	ll tmp=0;
	for(int i=1;i<=n;i++){
		tmp=0;
		if(v2[sor[i]].empty())continue;
		for(int j=0;j<v2[sor[i]].size();j++){
			tmp=max(tmp,ear[v2[sor[i]][j]]+a[v2[sor[i]][j]]);
		}
		ear[sor[i]]=tmp;
	}
	for(int i=1;i<=n;i++){
		if(v1[i].empty()){
			ans=max(ans,ear[i]+a[i]);
		}
	}
	for(int i=n;i>0;i--){
		tmp=MAX;
		if(v1[sor[i]].empty()){
			lat[sor[i]]=ans-a[sor[i]];
			continue;
		}
		for(int j=0;j<v1[sor[i]].size();j++){
			tmp=min(tmp,lat[v1[sor[i]][j]]-a[sor[i]]);
		}
		lat[sor[i]]=tmp;
	}
	
}
void solve(){
	int m,l,r;
	ll sum=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&l,&r);
		v1[l].push_back(r);
		v2[r].push_back(l);
		deg[r]++;
	}
	MapSort();
	key_path();
	for(int i=1;i<=n;i++){
		sum+=(lat[i]-ear[i]);
	}
	printf("%lld\n%lld",ans,sum);
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
