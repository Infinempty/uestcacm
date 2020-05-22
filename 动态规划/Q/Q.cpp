#include<bits/stdc++.h>
#define ll long long
#define MAX 1e14
using namespace std;
queue <ll> q;
ll a[500005],b[500005],dp[500005];
void solve(){
	int n,top=1;
	ll tmpa,tmpb,tmp_max=0,tmp=0,now=1;
	scanf("%d",&n);
	a[0]=b[0]=MAX;
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&tmpa,&tmpb);
		while(b[top-1]<=tmpb&&top>1)top--;
		a[top]=tmpa;b[top]=tmpb;
		top++;
	}
	for(int i=1;i<top;i++){
		while(!q.empty()&&dp[now]<=a[i]){
			now++;
			q.front();
		}
		if(q.empty()){
			dp[i]=a[i]+2*b[i];
		}else{
			dp[i]=min(q.front(),a[i]+2*b[now]);
		}
		/*for(int j=0;j<i;j++){
			tmp_max=min(max(dp[j],a[i])+2*b[j+1],tmp_max);
		}*/
		q.push(dp[i]+2*b[i+1]);
	}
	printf("%lld",dp[top-1]);
	
}
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
