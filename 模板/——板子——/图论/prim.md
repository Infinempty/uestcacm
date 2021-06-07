```c++

//prim
#define INF	100000000
const int MAX = 5010,MAXE=200010;
int index[MAX], fa[MAX],flag[MAX],Asize;
vector<pair<int, int> > A1;//(key,id)初始化push的时候key为INF
//A1.push_back({ 1,1 });占用0
struct Line { int to, next,w; }e[2*MAXE];
int h[MAX], cnt = 1;
inline void Add(int u, int v,int w) { e[cnt] = Line{ v,h[u],w }; h[u] = cnt++; }
void min_heapify(int i) {
	int l = 2 * i, r = l + 1, smallest = i;
	if (l <= Asize && A1[l].first < A1[i].first)smallest = l;
	if (r <= Asize && A1[r].first < A1[smallest].first)smallest = r;
	if (smallest != i) {
		index[A1[i].second] = smallest;
		index[A1[smallest].second] = i;
		swap(A1[i], A1[smallest]);
		min_heapify(smallest);
	}
}
void build_min_heap() {
	Asize = A1.size()-1;
	for (int i = Asize / 2; i >= 1; i--)min_heapify(i);
}
pair<int, int> extract_min() {
	if (Asize < 1)return { 0,0 };
	pair<int, int> min = A1[1];
	A1[1] = A1[Asize];
	index[A1[1].second] = 1;
	Asize--;
	min_heapify(1);
	return min;
}
void decrease_key(int i, int key) { //把A[i]增加为key
	int id = index[i];
	if (key >= A1[id].first)return;
	A1[id].first = key;
	while (id > 1 && A1[id / 2].first > A1[id].first) {
		index[i] = id / 2;
		index[A1[id / 2].second] = id;
		swap(A1[id / 2], A1[id]);
		id = id >> 1;
	}
}
void insert(int key) {
	Asize++;
	A1.push_back({ INF,Asize });
	index[Asize] = Asize;
	decrease_key(Asize, key);
}
int ans,nums;
void Prim(int r) {
	A1[r].first = 0;
	//build_min_heap();
	while (Asize > 0) {
		pair<int, int> u = extract_min();
		if (u.first != INF) {
			ans += u.first;
			nums++;
			flag[u.second] = 1;
			for (int j = h[u.second]; j; j = e[j].next) {
				int v = e[j].to;
				if (!flag[v] && e[j].w < A1[index[v]].first) {
					fa[v] = u.second;
					decrease_key(v, e[j].w);
				}
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int f, t, w;
		scanf_s("%d %d %d", &f, &t, &w);
		Add(f, t, w);
		Add(t, f, w);
	}
	A1.push_back({ 0,0 });
	for (int i = 1; i <= n; i++) {
		A1.push_back({ INF,i });
		index[i] = i;
	}
	Asize = A1.size() - 1;
	Prim(1);
	if (nums == n)cout << ans;
	else cout << "orz";
	return 0;
}

```

