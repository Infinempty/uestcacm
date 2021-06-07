```c++
#include<iostream>
using namespace std;
//暴力
int getlca(int x, int y) {
	while (x != y) {
		if (depth[x] >= depth[y])x = fa[x];
		else y = fa[y];
	}
	return x;
}
//倍增
const int maxn=100, maxlog=1;
int de[maxn], anc[maxn][maxlog],fi[maxn],ne[maxn],to[maxn];
void dfs(int x, int fa) {
	de[x] = de[fa] + 1;
	anc[x][0] = fa;
	for (int i = 1; i < maxlog; i++)anc[x][i] = anc[anc[x][i - 1]][i - 1];
	for (int i = fi[x]; i; i = ne[i])
		if (to[i] != fa)
			dfs(to[i], x);
}
int getlca(int x, int y) {
	if (de[x] < de[y])swap(x, y);
	for (int i = maxlog - 1; ~i; --i)//等价i>=0
		if (de[anc[x][i]] >= de[y])
			x = anc[x][i];
	if (x == y)return x;
	for (int i = maxlog - 1; ~i; --i) {
		if (anc[x][i] != anc[y][i])
			x = anc[x][i], y = anc[y][i];
		return anc[x][0];
	}
}
```

