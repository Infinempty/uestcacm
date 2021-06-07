#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int, int>
#define vi vector<int>
#define endl '\n'
const int mod = 1e9 + 7;
// const int mod = 998244353;
const int inf = 1e9;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        string ans;
        int fg = 0;
        if (s.size() >= 7) {
            if (s == "ikimasu") {
                ans = "itte";
                fg = 1;
            } else if (s.substr(s.size() - 7, 7) == "chimasu") {
                ans = s.substr(0, s.size() - 7) + "tte";
                fg = 1;
            } else if (s.substr(s.size() - 7, 7) == "shimasu") {
                ans = s.substr(0, s.size() - 7) + "shite";
                fg = 1;
            }
            if (fg) {
                cout << ans << endl;
                continue;
            }
        }
        if (s.substr(s.size() - 6, 6) == "rimasu") {
            ans = s.substr(0, s.size() - 6) + "tte";
        } else if (s.substr(s.size() - 6, 6) == "mimasu") {
            ans = s.substr(0, s.size() - 6) + "nde";
        } else if (s.substr(s.size() - 6, 6) == "bimasu") {
            ans = s.substr(0, s.size() - 6) + "nde";
        } else if (s.substr(s.size() - 6, 6) == "nimasu") {
            ans = s.substr(0, s.size() - 6) + "nde";
        } else if (s.substr(s.size() - 6, 6) == "kimasu") {
            ans = s.substr(0, s.size() - 6) + "ite";
        } else if (s.substr(s.size() - 6, 6) == "gimasu") {
            ans = s.substr(0, s.size() - 6) + "ide";
        }
        
        cout << ans << endl;
    }
    // cout.flush();
    // system("pause");
}