#include<bits/stdc++.h>
#define ll long long
#define MAX 0x3f3f3f3f
using namespace std;
int m[105][105],visx[105],visy[105],cx[105],cy[105];
int wx[105],wy[105],n,slack[105];
int minx=0x3f3f3f3f;
bool match(int u){
	visx[u]=1;
	int t=0x3f3f3f3f;
	for(int v=1;v<=n;v++){
		if(m[u][v]==MAX||m[u][v]==-1*MAX||visy[v])continue;
		t=wx[u]+wy[v]-m[u][v];
		if(t==0){
			visy[v]=1;
			if(cy[v]==-1||match(cy[v])){
				cx[u]=v;
				cy[v]=u;
				return true;
			}
		}else if(t>0){
			slack[v]=min(slack[v],t);
		}
	}
	return false;
}
int solve(){
	memset(cx,-1,sizeof(cx));
	memset(cy,-1,sizeof(cy));
	memset(wx,0,sizeof(visx));
	memset(wy,0,sizeof(visy));
	int ans=0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(m[i][j]==MAX||m[i][j]==-1*MAX)continue;
			wx[i]=max(wx[i],m[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		memset(slack,0x3f3f3f3f,sizeof(slack));
		while(1){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(match(i))break;
			for(int j=1;j<=n;j++){
				if(!visy[j]&&minx>slack[j]){
					minx=slack[j];
				}
			}
			for(int j=1;j<=n;j++){
				if(visx[j])wx[j]-=minx;
				if(visy[j])wy[j]+=minx;
				else slack[j]-=minx;
			}
		}
	}
	for(int i=1;i<=n;i++)
		ans+=m[i][cx[i]];
	return ans;
	
}
int gra[105][105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&gra[i][j]);
		}
	}
	int l=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&m[i][j]);
		}
	}
	int t1=solve();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			m[i][j]*=-1;
		}
	}
	int t2=solve();
	printf("%d \n%d",-1*t2,t1);
	
}