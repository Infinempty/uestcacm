```c++
#include<queue>
using namespace std;
//链式前向星
#define INF 100000000;
const int MAX = 100;
int cnt, head[MAX],n,dis[MAX],fa[MAX],flag[MAX];
struct edges
{
	int to, val, next;
}edge[2 * MAX];
/*struct nodes
{
	int dis = INF;
	int fa = 0, flag = 0;
};*/
void bfs(int root) {
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	dis[root] = 0;
	flag[root] = 1;
	queue<int> Q;
	Q.push(root);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int j = head[u]; j; j = edge[j].next) {
			int k = edge[j].to;
			if (!flag[k]) {
				flag[k] = 1;
				dis[k] = dis[u] + edge[j].val;
				fa[k] = u;
				Q.push(k);
			}
		}
	}
}
//绘制bfs树上路径
void paintpath(int s, int v) {
	if (v == s)printf("%d\n", s);
	else if (fa[v] == 0)printf("no path");
	else {
		paintpath(s, fa[v]);
		printf("%d", v);
	}
}
```

