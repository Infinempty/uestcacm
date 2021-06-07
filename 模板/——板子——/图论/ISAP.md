```c++
#include<bits/stdc++.h>
#define ll long long
#define N 1205
#define INF 1e16
#define IOS ios::sync_with_stdio(false),cin.tie(0)

#define mod 1000000007
using namespace std;
int n, m;
struct ISAP {
	struct line {
		int from, to, next; ll flow;
	}e[240005];
	int h[N], d[N], cur[N], pre[N], num[N], cnt = 1, s, t;
	queue<int>Q;
	inline void Add(int u, int v, ll f) {
		e[++cnt] = line{ u,v,h[u],f }; h[u] = cnt;
		e[++cnt] = line{ v,u,h[v],0 }; h[v] = cnt;
	}
	bool BFS() {
		memset(d, -1, sizeof d);
		d[t] = 0;
		Q.push(t);
		while (!Q.empty()) {
			int u = Q.front(); Q.pop();
			cur[u] = h[u];
			for (int i = h[u]; i; i = e[i].next) {
				int v = e[i].to;
				if (!e[i].flow && !~d[v]) {
					d[v] = d[u] + 1;
					Q.push(v);
				}
			}
		}
		return d[s] != -1;
	}
	ll Augment() {
		int u = t;
		ll res = 2147483648;//此处更新为边权上限
		while (u != s) {
			res = min(res, e[pre[u]].flow);
			u = e[pre[u]].from;
		}
		u = t;
		while (u != s) {
			e[pre[u]].flow -= res;
			e[pre[u] ^ 1].flow += res;
			u = e[pre[u]].from;
		}
		return res;
	}
	ll MaxFlow(int a,int b) {
		s = a, t = b;
		ll res = 0;
		//memset(num, 0, sizeof num);
		BFS();
		for (int i = 0; i < N; i++)num[d[i]]++;
		int u = s;
		while (d[s] < N) {
			if (u == t) {
				res += Augment();
				u = s;
			}
			bool Advanced = 0;
			for (int i = cur[u]; i; i = e[i].next) {
				int v = e[i].to;
				if (e[i].flow && d[u] == d[v] + 1) {
					Advanced = 1;
					cur[u] = pre[v] = i;
					u = v;
					break;
				}
			}
			if (!Advanced) {
				int m = N - 1;
				for (int i = h[u]; i; i = e[i].next) {
					if (e[i].flow) m = min(m, d[e[i].to]);
				}
				if (--num[d[u]] == 0)break;
				num[d[u] = m + 1]++;
				cur[u] = h[u];
				if (u != s)u = e[pre[u]].from;
			}
		}
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

