/*#include<bits/stdc++.h>
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
	int l=1
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
	
}*/
#pragma GCC optimize (3)
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<functional>
#include<cassert>
#include<numeric>
#include<algorithm>
#include<cctype>
#include<ctime>
#include<unordered_map>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>*/
//#include<ext/rope>
#define ll long long
#define ull unsigned long long
#define INF 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define N 150
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
const double PI=acos(-1.0);
const double eps=1e-6;
struct MinCost {
	struct line {
		int to, rev, flow, val;
		/*line() {}
		line(int _to, int _rev, int _flow, int _val) :
			to(_to), rev(_rev), flow(_flow), val(_val) {}*/
	};
	vector<line>G[N];
	int S, T, dis[N], flow, ans, ptr[N];
	bool vis[N];
	queue<int>Q;
	inline void Add(int u, int v, int flow, int cost) {
		G[u].push_back({ v,(int)G[v].size(),flow,cost });
		G[v].push_back({ u,(int)G[u].size() - 1,0,-cost });
	}
    inline void init() {
		for (int i = 0; i < N; i++)G[i].clear();
		flow = ans = 0;
        ans=INF;
	}
	bool SPFA() {
		memset(dis, 0x7f, sizeof dis);
		memset(vis, false, sizeof vis);
		Q.push(S);
		dis[S] = 0;
		while (!Q.empty()) {
			int u = Q.front(); Q.pop();
			//cout << u<<' '<<dis[u] << '\n';
			vis[u] = 0;
			for (auto& e : G[u]) {
				if (e.flow && dis[e.to] > dis[u] + e.val) {
					dis[e.to] = dis[u] + e.val;
					if (!vis[e.to]) {
						vis[e.to] = 1;
						Q.push(e.to);
					}
				}
			}
		}
		return dis[T] != 0x7f7f7f7f;
	}
	int Dinic(int x, int flow) {
		int left = flow;
		if (x == T)return flow;
		vis[x] = 1;
		for (int& i = ptr[x]; i < G[x].size() && left && flow; i++) {
			line& e = G[x][i];
			if (dis[e.to] == dis[x] + e.val && e.flow && !vis[e.to]) {
				//cout << e.to << ' ' << dis[e.to] << ' ' << e.flow << '\n';
				int t = Dinic(e.to, min(e.flow, left));
				e.flow -= t;
				G[e.to][e.rev].flow += t;
				left -= t;
			}
		}
		if (!left)vis[x] = 0;
		return flow - left;
	}
	int MinCostFlow(int u, int v) {
		S = u, T = v;
		while (SPFA()) {
			memset(ptr, 0, sizeof ptr);
			int d = Dinic(S, INF);
			flow += d;
			ans =min(ans,d * dis[T]);
			//cout << flow << ' ' << ans << '\n';
		}
		return ans;
	}
}T;

inline int read()
{
    int x=0,f=1;
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
int a[50][50],n;
bool judge(int k){
    T.init();
    for(int i=1;i<=n;i++){
        T.Add(100,i,1,0);
        T.Add(i+31,101,1,0);
        for(int j=1;j<=n;j++){
            if(a[i][j]>=k)T.Add(i,j+31,1,a[i][j]);
        }
    }
    T.MinCostFlow(100,101);
    if(T.flow==n&&T.ans>=k)return 1;
    return 0;
}
signed main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin>>n;
    vector<int>v;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            v.push_back(a[i][j]);
        }
    }
    sort(v.begin(),v.end());
    unique(v.begin(),v.end());
    int l=-1,r=v.size();
    while(l+1<r){
        int mid=l+r>>1;
        if(judge(v[mid]))l=mid;
        else r=mid;
    }
    cout<<l<<'\n';
    return 0;
}
