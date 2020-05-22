#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector <pair<ll,ll> >v[100005],v1[100005];
bool sta[100005];
ll k,sum=0;
ll vis[100005],dp_up[100005];
struct link{
	ll son,val;
}dp_down[100005][3],dis[100005];

ll dfs(int n){
	if(vis[n])return 0;
	vis[n]=1;
	int tmp=0;
	for(int i=0;i<v[n].size();i++){
		if(dfs(v[n][i].first)){
			tmp=1;
			v1[n].push_back(v[n][i]);
			sum+=v[n][i].second;
		}
	}
	if(tmp||sta[n]){
		sta[n]=1;
		return 1;
	}
	else return 0;
}
ll dfs1(int n){
	int siz=v1[n].size();
	if(!siz){
		dp_down[n][1]=dp_down[n][2]={0,0};
		return 0;
	}
	ll max1=0,max2=0,max1_poi=0,max2_poi=0,tmp; 
	for(int i=0;i<siz;i++){
		if(i==0){
			max1=dfs1(v1[n][i].first); 
			max1+=v1[n][i].second;
			max1_poi=v1[n][i].first;
			continue;
		}
		tmp=dfs1(v1[n][i].first);
		tmp+=v1[n][i].second;
		if(tmp>=max1){
			max2=max1;
			max2_poi=max1_poi;
			max1=tmp;
			max1_poi=v1[n][i].first;
		}else if(tmp>max2)
			max2=tmp;
			max2_poi=v1[n][i].first;
	}
	dp_down[n][1]={max1_poi,max1};
	dp_down[n][2]={max2_poi,max2};
	return max1;
}
void dfs2(int n,ll now_val,int fa){
	int siz=v1[n].size();
	if(dp_down[fa][1].son==n){
		if(dp_down[fa][2].val>dp_up[fa]){
			dp_up[n]=dp_down[fa][2].val+now_val;
		}else{
			dp_up[n]=dp_up[fa]+now_val;
		}
	}else{
		if(dp_down[fa][1].val>dp_up[fa]){
			dp_up[n]=dp_down[fa][1].val+now_val;
		}else{
			dp_up[n]=dp_up[fa]+now_val;
		}
	}
	for(int i=0;i<siz;i++){
		dfs2(v1[n][i].first,v1[n][i].second,n);
	}
}
link dfs3(int n,int fa){
	int siz=v[n].size();
	link now_dis;
	if(dis[n].val)return dis[n];
	if(!siz){
		return {-1,-1};
	}
	for(int i=0;i<siz;i++){
		if(v[n][i].first==fa)continue;
		if(sta[v[n][i].first]){
			dis[n]={v[n][i].first,v[n][i].second};
			return {v[n][i].first,v[n][i].second};
		}
		now_dis=dfs3(v[n][i].first,n);
		if(now_dis.val!=-1){
			now_dis.val+=v[n][i].second;
			dis[n]=now_dis;
			return dis[n];
		}
	}
	return {-1,-1};
}


void solve(){
	ll n,a,b,val,ans=0;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<n;i++){
		scanf("%lld %lld %lld",&a,&b,&val);
		v[a].push_back({b,val});
		v[b].push_back({a,val});
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&val);
		sta[val]=true;
	}
	dfs(val);
	dfs1(val);
	dfs2(val,0,0);
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=n;i++){
		if(sta[i])continue;
		dfs3(i,0);
	}
	/*for(int i=1;i<=n;i++){
		cout<<i<<endl;
		if(sta[i]){
			cout<<dp_down[i][1].son<<" "<<dp_down[i][1].val<<endl;
			cout<<dp_down[i][2].son<<" "<<dp_down[i][2].val<<endl;
			cout<<dp_up[i]<<endl;
		}
		if(!sta[i])cout<<dis[i].son<<" "<<dis[i].val<<endl;
		cout<<endl;
	}
	cout<<sum;*/
	for(int i=1;i<=n;i++){
		if(sta[i]){
			ans=max(dp_down[i][1].val,dp_up[i]);
			ans=2*sum-ans;
		}else{
			ans=max(dp_down[dis[i].son][1].val,dp_up[dis[i].son]);
			ans=dis[i].val+2*sum-ans;
		}
		printf("%lld \n",ans);
	}
	
	
	
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
