#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll, int>
#define vi vector<int>
#define endl '\n'
const int mod = 1e9 + 7;
// const int mod = 998244353;
const int inf = 1e9;
const ll len = 1000000001;
ll p[1000005], d[1000005];
pii q[2000005];

inline int read(){
   int s=0;
   char ch=getchar();
   while(ch<'0'||ch>'9'){ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s;
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(0);
    ll n, a, b;
    n = read();
    a = read();
    b = read();
    for (int i = 1; i <= n; i++) p[i] = read();
    for (int i = 1; i <= n; i++) d[i] = read();
    ll l = 0;
    ll x = min(a, b) / n;
    a -= x * n;
    b -= x * n;
    int st = 1, ed = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q[++ed] = pii(p[i], 0);
        } else {
            q[++ed] = pii(len - p[i], 1);
        }
    }
    sort(q + st, q + ed + 1);
    ll ans = 0;
    while (st <= ed) {
        if (q[st].second == 0) {
            if (a) {
                a--;
                q[++ed] = pii(q[st].first + len, 1);
            }
        } else {
            if (b) {
                b--;
                q[++ed] = pii(q[st].first + len, 0);
            }
        }
        st++;
    }
    // for (int i = 1; i <= ed; i++) {
    //     cout << i << ' ' << q[i].first << ' ' << q[i].second << endl;
    // }
    // cout << q[st].first << ' ' << x << endl;
    printf("%lld", q[ed].first + x * 2 * len);
    // cout.flush();
    // system("pause");
}