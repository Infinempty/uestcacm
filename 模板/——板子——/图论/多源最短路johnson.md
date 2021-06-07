```c++
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;
#define INF 1000000000
#define ll long long
const int MAX = 3010, MAXE = 10010;
long long d[MAX], n, m, v[MAX];
bool  flag[MAX];
long long ans[MAX];
struct Line { int to, next, w; }e[MAXE];
int h[MAX], cnt = 1;
inline void Add(int u, int v, int w) { e[cnt] = Line{ v,h[u],w }; h[u] = cnt++; }
inline bool relax(int u, int v, int w) {
	if (d[u] != INF && d[v] > d[u] + w) {
		d[v] = d[u] + w;
		return 1;
	}
	return 0;
}
inline void init(int r) {
	for (int i = 1; i <= n; i++)d[i] = INF;
	memset(flag, 0, sizeof(flag));
	d[r] = 0;
}

int nums[MAX];
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
		nums[u]++;
		if (nums[u] > n - 1)return 0;
		for (int i = h[u]; i; i = e[i].next) {
			int v = e[i].to;
			if (d[v] > d[u] + e[i].w) {
				d[v] = d[u] + e[i].w;
				if (!flag[v]) {
					Q.push(v);
					flag[v] = 1;
				}
			}
		}
	}
	return 1;
}
void dijkstra(int r) {
	init(r);
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > Q;
	Q.push({ d[r],r });
	while (!Q.empty()) {
		pair<ll, int>u = Q.top();
		Q.pop();
		if (flag[u.second])continue;
		flag[u.second] = 1;
		for (int j = h[u.second]; j; j = e[j].next) {
			int v = e[j].to;
			if (!flag[v]) {
				if (d[v] > d[u.second] + e[j].w) {
					d[v] = d[u.second] + e[j].w;
					Q.push({ d[v],v });
				}
			}
		}
	}
}
bool johnson() {
	for (int i = 1; i <= n; i++) {
		Add(0, i, 0);
		//if(!SPFA(i))return 0;
	}
	if (!SPFA(0))return 0;
	for (int i = 1; i <= n; i++)
		v[i] = d[i];
	for (int i = 1; i <= n; i++)
		for (int j = h[i]; j; j = e[j].next)
			e[j].w +=( d[i] - d[e[j].to]);
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		ll ans=0;
		for (ll j = 1; j <= n; j++) {
			ll k = d[j]+ v[j] - v[i];
			if (d[j] == INF)k = INF;
			ans += j * k;
		}
		printf("%lld\n", ans);
	}
	return 1;
}
inline int read()
{
	static char ch;
	bool sgn = false;
	while ((ch = getchar()) < '0' || ch > '9')
		if (ch == '-')
			sgn = true;
	int res = ch - 48;
	while ((ch = getchar()) >= '0' && ch <= '9')
		res = res * 10 + ch - 48;
	return sgn ? -res : res;
}
int main() {
	cin >> n >> m;
	int f, t, w;
	while (m--) {
		f = read(), t = read(), w = read();
		if (f != t)Add(f, t, w);
		else if (w < 0) {
			cout << -1;
			return 0;
		}
	}
	if (!johnson()) {
		cout << -1;
	}
	return 0;
}
```

