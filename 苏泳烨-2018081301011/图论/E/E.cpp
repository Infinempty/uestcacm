#include<bits/stdc++.h>
#define ll long long
#define MAX 1e14
using namespace std;
int m[205][205],visx[205],visy[205],cx[205],cy[205];
int wx[205],wy[205],n;
int minx=0x3f3f3f3f;
bool match(int u){
	visx[u]=1;
	int t=0x3f3f3f3f;
	for(int v=101;v<=200;v++){
		if(m[u][v]==0||visy[v])continue;
		t=wx[u]+wy[v]-m[u][v];
		if(t==0){
			visy[v]=1;
			if(cy[v]==-1||match(cy[v])){
				cx[u]=v;
				cy[v]=u;
				return true;
			}
		}else if(t>0){
			minx=min(minx,t);
		}
	}
	return false;
}
void solve(){
	memset(cx,-1,sizeof(cx));
	memset(cy,-1,sizeof(cy));

	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&m[i][j+100]);
			m[j+100][i]=m[i][j+100];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=101;j<=100+n;j++){
			if(m[i][j]==0)continue;
			wx[i]=max(wx[i],m[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		while(1){
			minx=0x3f3f3f3f;
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(match(i))break;
			for(int j=1;j<=n;j++){
				if(visx[j])wx[j]-=minx;
				if(visy[j+100])wy[j+100]+=minx;
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans+=m[i][cx[i]];
	printf("%d",ans);
	
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
