```c++
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define pr pair<int,int>
#define N 100005
#define mod 1000000007
#define INF 2147483647
using namespace std;
int num[N];
const int MAX = 500005;
int A[MAX];//A为辅助数组，可以通用
struct FIB_H
{
	int min = 0, n = 0;
}fib_h[MAX];
struct FIB_nodes
{
	int child = 0, left = 0, right = 0, p = 0;
	int key = INF, degree = 0, id = 0;
	bool mark = 0;
}node[N];
inline bool cmp_node(FIB_nodes& nd1, FIB_nodes& nd2) { return nd1.key < nd2.key || nd1.id < nd2.id&& nd1.key == nd2.key; }
inline void FIB_addroots(FIB_H& H, int x) {
	int l = node[H.min].left, xl = node[x].left, xr = node[x].right;
	node[x].right = H.min;	node[x].left = l;	node[x].p = 0;
	node[H.min].left = node[l].right = x;
}
inline void FIB_insert(FIB_H& H, int id) {
	if (!H.min) {
		node[H.min = id].key = num[id];
		node[H.min].left = node[H.min].right = H.min;
		node[H.min].id = id;
	}
	else {
		node[id].key = num[id];	node[id].id = id;
		FIB_addroots(H, id);
		if (cmp_node(node[id], node[H.min]))H.min = id;
	}
	H.n++;
}
FIB_H FIB_union(FIB_H& H1, FIB_H& H2) {
	FIB_H H;
	int L1 = node[H1.min].left, L2 = node[H2.min].left, h1 = H1.min, h2 = H2.min;
	swap(node[H1.min].left, node[H2.min].left);
	node[L1].right = h2;	node[L2].right = h1;
	if (!H1.min || !H2.min)H.min = H1.min | H2.min;
	else H.min = cmp_node(node[H1.min], node[H2.min]) ? H1.min : H2.min;
	H.n = H1.n + H2.n;
	return H;
}
inline void FIB_removenodes(FIB_H& H, int x) {
	int  xl = node[x].left, xr = node[x].right;
	node[xl].right = xr;	node[xr].left = xl;
}
inline void FIB_link(FIB_H& H, int y, int x) {
	FIB_removenodes(H, y);
	if (node[x].child) {
		int kid = node[x].child;
		node[y].left = node[kid].left;
		node[node[kid].left].right = y;
		node[y].right = kid;
		node[kid].left = y;
	}
	else node[x].child = y,node[y].left = node[y].right = y;
	node[y].p = x;
	node[x].degree++;
	node[y].mark = 0;
}
void FIB_consolidate(FIB_H& H) {
	int dn = log2(H.n) + 2;
	fill_n(A, dn + 2, 0);
	while (H.min) {
		FIB_removenodes(H, H.min);
		int x = H.min;
		H.min = node[H.min].left == H.min ? 0 : node[H.min].left;
		node[x].left = node[x].right = x;
		int d = node[x].degree;
		while (A[d]) {
			int y = A[d];
			if (cmp_node(node[y], node[x]))swap(x, y);
			FIB_link(H, y, x);
			A[d] = 0;
			d++;
		}
		A[d] = x;
	}
	for (int i = 0; i < dn; i++) {
		if (A[i]) {
			if (!H.min) {
				H.min = A[i];
				node[H.min].left = node[H.min].right = H.min;
			}
			else {
				FIB_addroots(H, A[i]);
				if (cmp_node(node[A[i]], node[H.min]))H.min = A[i];
			}
		}
	}
}
int FIB_extract(FIB_H& H) {
	int z = H.min;
	if (z) {
		while (node[z].child) {
			int x = node[z].child;
			FIB_removenodes(H, x);
			node[z].child = node[x].left == x ? 0 : node[x].left;
			FIB_addroots(H, x);
		}
		FIB_removenodes(H, z);
		if (z == node[z].right)H.min = 0;
		else {
			H.min = node[z].right;
			FIB_consolidate(H);
		}
		H.n--;
	}
	return z;
}
void FIB_cut(FIB_H& H, int x, int y) {
	if (node[x].left == x)node[y].child = 0;
	else {
		FIB_removenodes(H, x);
		if (node[y].child == x)node[y].child = node[x].left;
	}
	node[y].degree--;
	FIB_addroots(H, x);
	node[x].mark = 0;
}
void FIB_cascading_cut(FIB_H& H, int y) {
	int z = node[y].p;
	if (z) {
		if (!node[y].mark)node[y].mark = 1;
		else {
			FIB_cut(H, y, z);
			FIB_cascading_cut(H, z);
		}
	}
}
inline void  FIB_decrease_key(FIB_H& H, int x, int k) {
	if (node[x].key <= k)return;
	node[x].key = k;
	int y = node[x].p;
	if (y && cmp_node(node[x], node[y])) {
		FIB_cut(H, x, y);
		FIB_cascading_cut(H, y);
	}
	if (cmp_node(node[x], node[H.min]))H.min = x;
}
bool dle[MAX];
int f[MAX];
int find(int x) { return f[x] ? f[x] = find(f[x]) : x; };
int main() {
	freopen("P3377_11.in", "r", stdin);
	freopen("cover.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		FIB_insert(fib_h[i], i);
	}
	int x = 1;
	while (m--) {
		int op, a, b;
		cin >> op;
		if (op == 1) {
			cin >> a >> b;
			if (dle[a] || dle[b])continue;
			int fa = find(a), fb = find(b);
			fib_h[++n] = FIB_union(fib_h[fa], fib_h[fb]);
			f[fa] = f[fb] = n;
		}
		else {
			cin >> a;
			if (dle[a]) {
				cout << -1 << '\n';
				continue;
			}
			b = FIB_extract(fib_h[find(a)]);
			cout << node[b].key << '\n';
			dle[b] = 1;
		}
	}
	return 0;
}
```

