#include<bits/stdc++.h>
#define ll long long
using namespace std; 
int a[1000010],vis[1000010],cnt[1000010];
vector<int> v;
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		cnt[a[i]]--;
		if(vis[a[i]])continue;
		while(!v.empty()){
			if(cnt[v.back()]==0||v.back()<a[i])break;
			vis[v.back()]=0;
			v.pop_back();
		}
		vis[a[i]]=1;
		v.push_back(a[i]);
	}
	for(int i=1;i<=k;i++){
		if(!vis[i]){
			cout<<"Kanade\n";
			return;
		}
	}
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
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
