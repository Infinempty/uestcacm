#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define vi vector<int>
#define endl '\n'
const int mod = 1e9 + 7;
// const int mod = 998244353;
const int inf = 1e9;
int s[100005], p[100005], t[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x >> p[0];
    t[0] = 0;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= k; i++) cin >> t[i];
    for (int i = 1; i <= k; i++) cin >> p[i];
    int mx = 0;
    for (int i = 0; i <= k; i++) {
        mx = max(mx, p[i] - t[i]);
    }
    int mn = (x + mx - 1) / mx;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] >= mn) ans++;
    }
    cout << ans;
}