```c++
#include<bits/stdc++.h>
#define ll long long
#define N 205
#define INF 1e16
#define IOS ios::sync_with_stdio(false),cin.tie(0)

#define mod 1000000007
using namespace std;
int n, m;
struct DINIC {
	struct line {
		int to, next; ll flow;
	}e[10005];
	int h[N], d[N], cur[N], cnt = 1, s, t;
	queue<int>Q;
	inline void Add(int u, int v, ll f) {
		e[++cnt] = line{ v,h[u],f }; h[u] = cnt;
		e[++cnt] = line{ u,h[v],0 }; h[v] = cnt;
	}
	bool BFS() {
		memset(d, -1, sizeof d);
		d[s] = 1;
		Q.push(s);
		cur[s] = h[s];
		while (!Q.empty()) {
			int u = Q.front(); Q.pop();
			for (int i = h[u]; i; i = e[i].next) {
				int v = e[i].to;
				if (e[i].flow && !~d[v]) {
					cur[v] = h[v];
					d[v] = d[u] + 1;
					Q.push(v);
				}
			}
		}
		return d[t] != -1;
	}
	ll Dinic(int u, ll flow) {
		ll left = flow;
		if (u == t)return flow;
		for (int i = cur[u]; i; i = e[i].next) {
			cur[u] = i;
			int v = e[i].to;
			if (e[i].flow && d[v] == d[u] + 1) {
				ll t = Dinic(v, min(left, e[i].flow));
				e[i].flow -= t;
				e[i ^ 1].flow += t;
				left -= t;
			}
			if (!left)return flow;
		}
		if (left)d[u] = -1;
		return flow - left;
	}
	ll MaxFlow(int u, int v) {
		s = u, t = v;
		//memset(cur, 0, sizeof(cur));
		ll res = 0;
		while (BFS())res += Dinic(s, INF);
		return res;
	}
}T;
int main() {
	IOS;
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		int u, v;
        ll w;
		cin >> u >> v >> w;
		T.Add(u, v, w);
	}
	cout << T.MaxFlow(s, t);
	return 0;

}
```

