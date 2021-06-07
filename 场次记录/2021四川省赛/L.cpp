#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define vi vector<int>
#define endl '\n'
const int mod = 1e9 + 7;
// const int mod = 998244353;
const int inf = 1e9;
int w[100005], vis[100005], ans[100005][105];
vector<int> eg[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        for (int j = 1; j <= 100; j++) ans[i][j] = inf;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        eg[u].push_back(v);
        eg[v].push_back(u);
    }
    for (int i = 1; i <= 100; i++) {
        queue<pii> q;
        for (int j = 1; j <= n; j++) {
            if (w[j] == i) q.push(pii(j, 0));
            vis[j] = 0;
        }
        while (!q.empty()) {
            pii u = q.front();
            q.pop();
            if (vis[u.first]) continue;
            vis[u.first] = 1;
            ans[u.first][i] = u.second;
            for (int j : eg[u.first]) {
                if (!vis[j]) q.push(pii(j, u.second + 1));
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        int res = inf, p, a;
        cin >> p >> a;
        for (int j = 1; j <= a; j++) {
            res = min(res, ans[p][j]);
        }
        cout << (res == inf ? -1 : res) << endl;
    }
    // cout.flush();
    // system("pause");
}