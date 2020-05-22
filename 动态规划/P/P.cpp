#include<bits/stdc++.h>
#define ll long long
int a[505],dp[505],b[505];
using namespace std; 
void solve(){
	int n,t,now;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1e9;
	}
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=i;j<=n;j++){
			now=a[j];
			while(t&&b[t]==now){
				b[t--]=0;
				now++;
			}
			b[++t]=now;
			if(t==1)dp[j]=min(dp[j],dp[i-1]+1);
		}
	}
	cout<<dp[n];
}
int main()
{
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
