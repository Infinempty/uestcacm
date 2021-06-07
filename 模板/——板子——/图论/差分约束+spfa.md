```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
#define INF 2147483647
const int MAX = 10010, MAXE = 500010;
struct Line { int to, next, w; }e[2 * MAXE];
int h[MAX], cnt = 1, ans[MAX], d[MAX], p[MAX], n, m, flag[MAX], nums[MAX];
inline void Add(int u, int v, int w) { e[cnt] = Line{ v,h[u],w }; h[u] = cnt++; }
inline bool relax(int u, int v, int w) {
	if (d[u] != INF && d[v] > d[u] + w) {
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
bool SPFA(int r) {
	queue<int> Q;
	init(r);
	flag[r] = 1;
	nums[r]++;
	Q.push(r);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		flag[u] = 0;
		for (int i = h[u]; i; i = e[i].next) {
			int v = e[i].to;
			if (d[v] > d[u] + e[i].w) {
				d[v] = d[u] + e[i].w;
				if (!flag[v]) {
					Q.push(v);
					flag[v] = 1;
					nums[v]++;
					if (nums[v] > n)return 0;
				}
			}
		}
	}
	return 1;
}
//dfs优化
/*
bool SPFA(int r) {
	flag[r] = 1;
	for (int i = h[r]; i; i = e[i].next) {
		int v = e[i].to;
		if (d[v] > d[r] + e[i].w) {
			if (flag[v])return 0;
			d[v] = d[r] + e[i].w;
			if(!SPFA(v)) return 0;
		}
	}
	flag[r] = 0;
	return 1;
}*/
int main() {
	cin >> n >> m;
	int op, u, v, we;
	while (m--) {
		scanf("%d%d%d", &op, &u, &v);
		if (op == 1)
			scanf("%d", &we), Add(u, v, -we);
		else if (op == 2)
			scanf("%d", &we), Add(v, u, we);
		else if (op == 3)
			Add(u, v, 0), Add(v, u, 0);
	}
	for (int i = 1; i <= n; i++) {
		Add(n + 1, i, 0);//跑差分的时候加一个超级源点，从他开始
	}
	init(n+1);
	if (!SPFA(n + 1)) {
		printf("No\n"); return 0;
	}
	printf("Yes\n");
	return 0;
}
```

