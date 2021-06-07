```c++
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define pr pair<int,int>
#define N 301
#define mod 1000000007
#define INF 2147483647
using namespace std;
string a;
int s[N], rk[N], ork[N<<1], sa[N], tmp[N], cnt[N],id[N],n,m;//m为最大字符值
bool cmp(int i, int j, int w) { return ork[i] == ork[j] && ork[i + w] == ork[j + w]; }
void getsa() {
	int i, p=0, w;
	for (i = 1; i <= n; i++)s[i] = a[i - 1] - 'a' + 1;
	for (i = 1; i <= n; i++)cnt[rk[i] = s[i]]++;
	for (i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
	for (i = n; i >= 1; i--)sa[cnt[rk[i]]--] = i;
	
	for (w = 1; w < n; w <<= 1,m=p) {
		for (p=0,i = n - w+1; i <= n; i++)id[++p] = i;
		for (i = 1; i <= n; i++)if (sa[i] > w)id[++p] = sa[i] - w;
		memset(cnt, 0, sizeof cnt);
		for (i = 1; i <= n; i++)cnt[tmp[i] = rk[id[i]]]++;
		for (i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
		for (i = n; i >= 1; i--)sa[cnt[tmp[i]]--] = id[i];
		memcpy(ork, rk, sizeof rk);
		for (i = 1,p=0; i <= n; i++) {
			rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
		}
	}
}
int ht[N];
void getht() {
	for (int i = 1, k = 0; i <= n; ++i) {
		if (k) --k;
		while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
		ht[rk[i]] = k;
	}
}
int main() {
	IOS;
	cin >> n >> a;
	m = 30;
	getsa();
	for (int i = 1; i <= n; i++)cout << rk[i] << ' ';
	cout << '\n';
	for (int i = 1; i <= n; i++)cout << sa[i] << ' ';
	for (int i = 1; i <= n; i++)cout << a.substr(sa[i] - 1, a.size()) << '\n';
	getht();
	cout << '\n';
	for (int i = 1; i <= n; i++)cout << ht[i] << ' ';
	return 0;
}
```

