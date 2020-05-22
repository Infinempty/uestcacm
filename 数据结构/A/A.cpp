#include<bits/stdc++.h>
#define ll long long
using namespace std; 
string in;
void solve(){
	int len,ans=0;
	stack<char> s;
	cin>>len;
	if(len==0){
		cout<<0<<"\n";
		return;
	}
	cin>>in;
	for(int i=0;i<len;i++){
		if(in[i]=='(')
			s.push(in[i]);
		else if(s.empty())
			ans++;
		else s.pop();
	}
	ans+=s.size();
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
}
