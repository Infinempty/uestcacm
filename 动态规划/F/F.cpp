#include <bits/stdc++.h>
#define ll long long
using namespace std;
char s[5005]; 
int dp[5005][5005];
void solve(){
	int len;
	scanf("%d",&len);
	scanf("%s",&s);
	for(int k=1;k<len;k++){
		for(int i=1,j=1+k;j<=len;i++,j++){
			if(s[i-1]==s[j-1])dp[i][j]=dp[i+1][j-1];
			else dp[i][j]=min(dp[i+1][j]+1,dp[i][j-1]+1);
		}
	}
	cout<<dp[1][len];
	
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t=1;
	//scanf("%d",&t);
	while(t--){
		solve();
	}
}
