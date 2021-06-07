```c++
#include<iostream>
using namespace std;
#define INF 100000000
const int MAX = 100, MAXE = 300;
struct Line { int to, next,w; }e[2 * MAXE];
int h[MAX], cnt = 1, ans[MAX], d[MAX], p[MAX],n,m;
inline void Add(int u, int v,int w) { e[cnt] = Line{ v,h[u],w }; h[u] = cnt++; }
inline bool relax(int u, int v, int w) {
	if (d[v] > d[u] + w) {
		d[v] = d[u] + w;
		p[v] = u;
		return true;
	}
	return false;
}
inline void init(int r) {
	for (int i = 1; i <= n; i++)d[i] = INF;
	memset(p, 0, sizeof(p));
	d[r] = 0;
}
bool bellmam_ford(int s) {
	init(s);
	for (int i = 0; i < n; i++) {
		bool jud = false;
		for (int j = 1; j <= n; j++)
			for (int k = h[j]; k; k = e[k].next)
				jud = relax(j,e[k].to, e[k].w);
		if (!jud) break;//若本轮没有修改，则下一轮一定也没有修改
	}
	for (int i = 1; i <= n; i++)
		for (int j = h[i]; j; j = e[j].next)
			if (d[e[j].to] > d[i] + e[j].w) return false;
	return true;
}
```

