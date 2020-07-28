#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll in[200050];
priority_queue<ll,vector<ll>,greater<ll> >q;
void solve(){
    ll n,a,b,ans=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&in[i]);
    	q.push(in[i]);
	}
	while(q.size()!=1){
		a=q.top();q.pop();
		b=q.top();q.pop();
		if(a==b){
			q.push(2*a);
		}else if((b/a)%2){
			ans=-1;
			break;
		}else {
			ans++;
			q.push(2*a);
			q.push(b);
		}
	}
	printf("%lld",ans);
}

signed main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}