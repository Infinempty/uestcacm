```c++
#include<queue>
using namespace std;
//链式前向星
#define INF 100000000;
const int MAX = 100;
int cnt, head[MAX], n, dis[MAX], fa[MAX], flag[MAX];
struct edges
{
	int to, val, next;
}edge[2 * MAX];
/*struct nodes
{
	int dis = INF;
	int fa = 0, flag = 0;
};*/
int time = 0,d[MAX],f[MAX];//dfs序,d为发现时间，f为完成时间
int topo[2*MAX];//拓扑排序数组，下标为完成时间
void dfs() {
	for (int i = 1; i <= n; i++) {
		if (!flag[i])
			dfsvisit(i);
	}

}
void dfsvisit(int i){
	d[i] = ++time;
	flag[i] = 1;
	for (int j = head[i] ; j; j = edge[j].next) {
		int k = edge[j].to;
		if (!flag[k]) {
			dis[k] = edge[j].val + dis[i];
			fa[k] = i;
			dfsvisit(k);
		}
	}
	//flag[i] = 2;//在有向图里可以用来判断前向边
	f[i] = ++time;
	//topo[time]=i;
}

//拓扑排序
int topost[MAX],cnt;
void toposort() {
	dfs();
	for (int j = 2 * n; j >= 1; j--) {
		if (topo[j]) {
			//printf("%d ", topo[j]);	//数组定义在line 17
			topost[++cnt] = topo[j];
		}
	}
}
void dfsontree(int root) {
	for (int j = head[root]; j; j = edge[j].next) {
		int k = edge[j].to;
		if (k != fa[root]) {
			fa[k] = root;
			//处理
			dfsontree(k);
		}
	}
}

//强连通分量kosaraju
int roots[MAX],rtcnt;//保存强连通分量的根
void scc() {
	dfs();
		//计算转置  或者直接在加边的时候整两套
	toposort();
	for (int i = 1; i <= n; i++) {
		int num = topost[i];
		if (!flag[num])
			roots[++rtcnt] = num;
			dfsvisit(num);
	}
}
//tarjan法
void DFS(int i)
{
	low[i] = dfn[i] = ++dfs_clock;
	stk[++top] = i;
	for (int p = last[i]; p; p = E[p].pre)
	{
		int j = E[p].v;
		if (dfn[j])
		{
			if (!belong[j]) low[i] = min(low[i], dfn[j]);
			continue;
		}

		DFS(j);
		low[i] = min(low[i], low[j]);
	}

	if (dfn[i] == low[i])
	{
		scc++;
		while (1)
		{
			int x = stk[top--];
			belong[x] = scc;
			size[scc]++;
			if (x == i) break;
		}
	}
}
```

