#include<bits/stdc++.h>
#define ll long long
#define INF 1e16
using namespace std;
bool cnt[505];
ll e[505][505],dis[505][505],ans[505];
int sr[505];
void Floyd(ll n){
	ll tmp=INF;
	//sr是加点顺序，通常情况下取sr[i]=i ，有特殊要求另行讨论 
	for(int k=1;k<=n;k++){
		for(int i=1;i<k;i++){
			for(int j=i+1;j<k;j++){
				tmp=min(tmp,e[sr[i]][sr[k]]+e[sr[k]][sr[j]]+dis[sr[i]][sr[j]]);
				ans[k]=min(ans[k],tmp);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[sr[i]][sr[j]]=min(dis[sr[i]][sr[j]],dis[sr[i]][sr[k]]+dis[sr[k]][sr[j]]);
			}
		}
		
	}
}
void solve(){
	ll n,m,k,a,b,w;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=n;i++){
		ans[i]=INF;
		for(int j=1;j<=n;j++){
			if(i==j)e[i][j]=dis[i][j]=0;
			else e[i][j]=dis[i][j]=INF;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%lld %lld %lld",&a,&b,&w);
		e[a][b]=e[b][a]=w;
		dis[a][b]=dis[b][a]=w;
	}
	ll t=n;
	for(t;t>n-k+1;t--){
		scanf("%d",&sr[t]);
		cnt[sr[t]]=1;
	}
	for(int i=1;i<=n;i++){
		if(!cnt[i])sr[t--]=i;
	}
	Floyd(n);
	for(int i=n;i>n-k;i--){
		if(ans[i]>=1e13)printf("-1\n");
		else printf("%lld\n",ans[i]);
	}
	
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
