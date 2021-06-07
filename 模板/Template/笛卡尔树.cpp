//HDU-1506:Largest Rectangle in a Histogram
#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define maxn 100005
using namespace std;
const double PI=acos(-1.0);
const double eps=1e-6;
bool vis[maxn];
ll n,top,a[maxn],siz[maxn],stk[maxn],son[maxn][2];
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void dfs(ll i)
{
	siz[i]++;
	if(son[i][1]!=0) dfs(son[i][1]);
	if(son[i][0]!=0) dfs(son[i][0]);
	siz[i]+=siz[son[i][0]];
	siz[i]+=siz[son[i][1]];
	return;
}
signed main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	while(1){
		n=read();
		top=0;
		if(!n) break;
		for(ll i=1;i<=n;i++) a[i]=read();
		memset(stk,0,sizeof(stk));
		memset(son,0,sizeof(son));
		memset(siz,0,sizeof(siz));
		memset(vis,0,sizeof(vis));
		for(ll i=1;i<=n;i++){
			ll node=0,j;
			while(top>0 && a[stk[top]]>a[i]){
				j=stk[top--];
				son[j][1]=node,node=j;
			}
			son[i][0]=node,stk[++top]=i;
		}
		ll node=0,j;
		while(top){
			j=stk[top--];
			son[j][1]=node,node=j;
		}
		for(int i=1;i<=n;i++){
			vis[son[i][0]]=1;
			vis[son[i][1]]=1;
		}
		int r=-1;
		for(int i=1;i<=n;i++) if(!vis[i]) r=i;
		dfs(r);
		ll ans=0;
		for(ll i=1;i<=n;i++) ans=max(a[i]*siz[i],ans);
		cout<<ans<<endl;
	}
	return 0;
}
