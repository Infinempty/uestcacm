```c++
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
#define INF 2147483647
const int MAX = 10010, MAXE = 500010;
struct Line { int to, next, w; }e[2 * MAXE];
int h[MAX], cnt = 1, ans[MAX], d[MAX], p[MAX], n, m, flag[MAX];
inline void Add(int u, int v, int w) { e[cnt] = Line{ v,h[u],w }; h[u] = cnt++; }
inline bool relax(int u, int v, int w) {
	if (d[u]!=INF&&d[v] > d[u] + w) {
		d[v] = d[u] + w;
		p[v] = u;
		return 1;
	}
	return 0;
}
inline void init(int r) {
	for (int i = 1; i <= n; i++)d[i] = INF;
	memset(p, 0, sizeof(p));
	d[r] = 0;
}
//优先队列
void dijkstra(int r) {
	init(r);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > Q;
	Q.push({ d[r],r });
	while (!Q.empty()) {
		pair<int, int>u = Q.top();
		Q.pop();
		if (flag[u.second])continue;
		flag[u.second] = 1;
		for (int j = h[u.second]; j; j = e[j].next) {
			int v = e[j].to;
			if (!flag[v]) {
				bool p=relax(u.second, v, e[j].w);
				if (p)Q.push({ d[v],v });
			}
		}
	}
}
int main() {
	int r;
	cin >> n >> m >> r;
	for (int i = 1; i <= m; i++) {
		int f, t, w;
		scanf_s("%d %d %d", &f, &t, &w);
		Add(f, t, w);
	}
	dijkstra(r);
	printf("%d", d[1]);
	for (int i = 2; i <= n; i++)printf(" %d", d[i]);
}
```

