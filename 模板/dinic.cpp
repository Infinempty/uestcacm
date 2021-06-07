const int INF=0x3f3f3f3f;
const int MAXN=200050;

struct Edge{
	int from,to;
	ll cap,flow;
	Edge(int from,int to,ll cap,ll flow){
		this->from=from;
		this->to=to;
		this->cap=cap;
		this->flow=flow;
	}
};

struct Dinic{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool vis[MAXN];
	int d[MAXN];
	int cur[MAXN];
	void AddEdge(int from,int to,int cap){
		edges.eb(Edge(from,to,cap,0));
		edges.eb(Edge(to,from,0,0));
		m=edges.size();
		G[from].eb(m-2);
		G[to].eb(m-1);
	}
	bool BFS(){
		memset(vis,0,sizeof(vis));
		queue<int> q;
		q.push(s);
		d[s]=0;
		vis[s]=1;
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=0;i<G[x].size();i++){
				Edge &e=edges[G[x][i]];
				if(!vis[e.to]&&e.cap>e.flow){
					vis[e.to]=1;
					d[e.to]=d[x]+1;
					q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	ll DFS(int x,ll a){
		if(x==t||a==0)return a;
		ll flow=0,f;
		for(int &i=cur[x];i<G[x].size();i++){
			Edge &e=edges[G[x][i]];
			if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
				e.flow+=f;
				edges[G[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(a==0)break;
			}
		}
		return flow;
	}
	ll Maxflow(int s,int t){
		this->s=s,this->t=t;
		ll flow=0;
		while(BFS()){
			memset(cur,0,sizeof(cur));
			flow+=DFS(s,LINF);
		}
		return flow;
	}
}dinic;