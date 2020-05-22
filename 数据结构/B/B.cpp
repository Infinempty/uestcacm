#include<bits/stdc++.h>
#define ll long long
using namespace std; 
string in;
int datam[1000010];
int find_m(int x)
{
	if(datam[x]==x)return x;
	datam[x]=find_m(datam[x]);
	return datam[x];
}
void solve(){
	int n,temp,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		datam[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>temp;
		if(i==temp)continue;
		datam[find_m(i)]=find_m(temp);
	}
	for(int i=1;i<=n;i++)
		if(datam[i]==i)ans++;
	cout<<ans;
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
