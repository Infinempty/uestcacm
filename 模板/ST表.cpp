#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100001];
int lg[100001]={-1};
int maxn[100001][50];
int minn[100001][50];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void create_ST(int n){
	for(int i=1;i<=n;i++){
		lg[i]=lg[i/2]+1;
		maxn[i][0]=a[i];
		minn[i][0]=a[i];
	}
	for(int i=1;i<=lg[n];i++)
    {
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            maxn[j][i]=max(maxn[j][i-1],maxn[j+(1<<(i-1))][i-1]);
            minn[j][i]=min(minn[j][i-1],minn[j+(1<<(i-1))][i-1]);
        }
    }
}
ll query_max(int l,int r){
	int len=lg[r-l+1];
    return max(maxn[l][len],maxn[r-(1<<(len))+1][len]);
}
ll query_min(int l,int r){
	int len=lg[r-l+1];
    return min(minn[l][len],minn[r-(1<<(len))+1][len]);
}
void solve(){
	int n,m,l,r;
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	create_ST(n);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		printf("%d\n",query_max(l,r)-query_min(l,r));
	}
}
signed main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--){
		solve();
	}
}
