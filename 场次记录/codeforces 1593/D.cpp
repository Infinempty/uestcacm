//#pragma GCC target("avx2")
//#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define lc(x) ((x)<<1)
#define rc(x) (((x)<<1)|1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;

const ll MOD = 1e9 + 7;
const ll LINF = 1e18;
const int INF = 0x3f3f3f3f;
const int MAXE = 5000050;
const int MAXN = 200050;
const int bk_sz = 3420;
mt19937 rnd(114514);

ll a[MAXN];
bool check(int n, ll ai, ll t) {
    int cnt = 0;
    for (int k = 1;k <= n;k++) {
        if (__gcd(t, abs(a[k] - ai)) == t) {
            cnt++;
        }
    }
    return cnt >= n;
}
void mainwork(int T) {
    int n;
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    ll ans = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            ll gcd = a[j] - a[i];
            if (check(n, a[i], gcd)) {
                if (gcd == 0) {
                    puts("-1");
                    return;
                }
                ans=max(ans,gcd);
                continue;
            }
            for (ll t = 2;t * t <= gcd;t++) {
                if (gcd % t != 0)continue;
                if (check(n, a[i], t)) {
                    ans = max(ans, t);
                }
                if (check(n, a[i], gcd / t)) {
                    ans = max(ans, gcd / t);
                }
            }
        }
    }
    printf("%lld\n", ans);
}
signed main() {
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in", "r", stdin);
    freopen("Ranulx.out", "w", stdout);
#endif
    int t = 1;
    scanf("%d", &t);
    for (int i = 1;i <= t;i++) {
        mainwork(i);
    }
}