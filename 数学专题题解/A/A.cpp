#include<iostream>
#define ll long long
using namespace std;
void solve(){
	int ans=0,sta;
	int n,tmp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		if(tmp%2)ans++;
	}
	if(ans==0)printf("Bob");
	else printf("Alice");
}
int main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--){
		solve();
	}
}