```c++
struct trie {
	unordered_map<int, int>nxt[400 * N];
	bool vis[400 * N];
	int sz = 0, rt;
	void init() {
		sz = 0;
		rt = newnode();
	}
	int newnode() {
		nxt[++sz].clear();
		vis[sz] = 0;
		return sz;
	}
	int add(int len) {
		int p = rt;
		for (int i = 1; i <= len; i++) {
			int& t = nxt[p][b[i]];//b为插入字典树的串
			if (!t)t = newnode();
			p = t;
		}
		return p;
	}
}T;
//查询就是从rt开始跳nxt
for (auto k : L) {
	if (!T.nxt[p][k])break;
	p = T.nxt[p][k];
}
```

