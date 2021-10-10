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
const int MAXN = 1000050;
const int bk_sz = 3420;
mt19937 rnd(114514);

int a[MAXN];
int check(vector<int>& tmp) {
    int sum = 0, ans = 0;
    map<int, int> mp[2];
    mp[1].insert(mkp(0, -1));
    for (int i = 0;i < tmp.size();i++) {
        sum ^= tmp[i];
        if (mp[i & 1].count(sum)) {
            ans = max(ans, (i - mp[i & 1][sum]));
        }
        else {
            mp[i & 1].insert(mkp(sum, i));
        }
    }
    return ans;
}
void mainwork(int T) {
    int n;
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d", a + i);
    }
    int now = 0, ans = 0;
    vector<int> tmp;

    for (int p = 19;~p;p--) {
        now |= (1 << p);
        tmp.clear();

        for (int i = 1;i <= n;i++) {
            if ((a[i] >> p) & 1) {
                tmp.eb(a[i] & now);
            }
            else {
                ans = max(ans, check(tmp));
                tmp.clear();
            }
        }
        ans = max(ans, check(tmp));

    }
    printf("%d\n", ans);
}
signed main() {
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in", "r", stdin);
    freopen("Ranulx.out", "w", stdout);
#endif
    int t = 1;
    //scanf("%d",&t);
    for (int i = 1;i <= t;i++) {
        mainwork(i);
    }
}