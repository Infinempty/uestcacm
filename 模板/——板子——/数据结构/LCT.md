```c++
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define pr pair<int,int>
#define N 100005
#define mod 1000000007
#define INF 2147483647

#define lc(x) nd[(x)].ch[0]
#define rc(x) nd[(x)].ch[1]
#define fa(x) nd[(x)].ch[2]
using namespace std;

struct SplayTree
{
	int ch[3],cnt, v,sum;bool rev;
	SplayTree() {}
	SplayTree(int _f, int _v) :v(_v), cnt(1),rev(0),sum(_v) {
		ch[0] = ch[1] = 0, ch[2] = _f;
	}
}nd[N];
int rt, siz, x,stk[N];
void update(int x) {}
void push_up(int x) {
	// ……
	nd[x].sum = nd[rc(x)].sum ^ nd[x].v ^ nd[lc(x)].sum;
	return;
}
void push_down(int x) {
	if (nd[x].rev) {
		nd[x].rev = 0;
		nd[lc(x)].rev ^= 1;
		nd[rc(x)].rev ^= 1;
		swap(lc(x), rc(x));
	}
	return;
}
inline bool isroot(int x) { return !(lc(fa(x)) == x || rc(fa(x)) == x); }
void rotate(int& x) {
	int y = fa(x), z = fa(y), l = rc(y) == x, r = l ^ 1;
	if (!isroot(y))nd[z].ch[rc(z) == y] = x;
	fa(x) = z; fa(y) = x;
	fa(nd[x].ch[r]) = y;
	nd[y].ch[l] = nd[x].ch[r];
	nd[x].ch[r] = y;
	push_up(y);
	push_up(x);
	return;
}
void splay(int x) {
	int top = 0;
	stk[++top] = x;
	for (int i = x; !isroot(i); i = fa(i))stk[++top] = fa(i);
	while (top)push_down(stk[top--]);
	while (!isroot(x)) {
		int y = fa(x), z = fa(y);
		if (!isroot(y)) {
			if (lc(y) == x ^ lc(z) == y)rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	return;
}
//连续两次access，第二次返回值表示这两个节点的lca
int access(int x) {
	int i;
	for (i = 0; x; i = x, x = fa(x))splay(x), rc(x) = i, push_up(x);
	return i;
}
void Makeroot(int x) {
	access(x);
	splay(x);
	nd[x].rev ^= 1;
	return;
}
int getroot(int x) {
	access(x);
	splay(x);
	while (lc(x)) x = lc(x);
	//splay(x);
	return x;
}
void cut(int x, int y) {
	if (getroot(x) != getroot(y))return;
	Makeroot(x);
	access(y);
	splay(y);
	if (lc(y) != x || rc(x))return;
	fa(x) = lc(y) = 0;
	return;
}
void link(int x, int y) {
	Makeroot(x);
	fa(x) = y;
	return;
}
void split(int x, int y) {
	Makeroot(x);
	access(y);
	splay(y);
}

int main() {
	IOS;
	int n, op, x, y,m,v;
	cin >> n>>m;
	for (int i = 1; i <= n; i++) {
		cin>>v;
		nd[i] = SplayTree(0, v);
	}
	while (m--) {
		cin >> op >> x >> y;
		if (op == 0) { //x到y xor和
			Makeroot(x);
			access(y);
			splay(y);
			cout << nd[y].sum<<'\n';
		}
		else if (op == 1) {
			if (getroot(x) != getroot(y)) {
				link(x, y);
			}
		}
		else if (op == 2) {
			cut(x, y);
		}
		else { //更改节点x的值为y
			Makeroot(x);
			nd[x].v = y;
			push_up(x);
		}
	}
}
```

