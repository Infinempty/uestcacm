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

bool ok = 0;
int pri[MAXN], pid[MAXN], tot;
bool vis[MAXN];
void prework(int n) {
    tot = 0;
    for (int i = 2;i <= n;i++) {
        if (!vis[i]) {
            pri[++tot] = i;
            pid[i] = tot;
        }
        for (int j = 1;j <= tot && i * pri[j] <= n;j++) {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)break;
        }
    }
}
class Solution {
public:
    int fa[MAXN];
    int bel[MAXN];
    int find(int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }
    void merge(int x, int y) {
        int fax = find(x), fay = find(y);
        if (fax == fay)return;
        fa[fax] = fay;
    }

    bool gcdSort(vector<int>& nums) {
        if (!ok) {
            prework(100000);
            ok = 1;
        }
        for (int i = 1;i <= tot;i++)fa[i] = i;
        for (int i = 0;i < nums.size();i++) {
            int tmp = nums[i];
            vector<int> product;
            for (int j = 1;pri[j] * pri[j] <= tmp && j <= tot;j++) {
                if (tmp % pri[j] == 0) {
                    bel[i] = j;
                    product.eb(j);
                    while (tmp % pri[j] == 0) {
                        tmp /= pri[j];
                    }
                }
            }
            if (tmp > 1) {
                bel[i] = pid[tmp];
                product.eb(pid[tmp]);
            }
            for (auto id : product) {
                merge(bel[i], id);
            }
        }
        vector<pair<int, int> > st;
        for (int i = 0;i < nums.size();i++) {
            st.eb(mkp(nums[i], bel[i]));
        }
        sort(all(st));
        for (int i = 0;i < st.size();i++) {
            if (find(bel[i]) != find(st[i].second))return false;
        }
        return true;
    }
}S;
void mainwork(int T) {
    vector<int> nums = { 5,2,6,2 };
    vector<int> nums2 = { 7,21,3 };
    printf("%d\n%d", S.gcdSort(nums2), S.gcdSort(nums));
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