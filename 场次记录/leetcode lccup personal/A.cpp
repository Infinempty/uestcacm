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

const ll MOD=1e9+7;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXE=5000050;
const int MAXN=200050;
const int bk_sz=3420;
mt19937 rnd(114514);

class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
        map<int,int> cnt;
        for(auto &now:source){
            for(auto i:now){
                cnt[i]++;
            }
        }
        int ans=0;
        for(auto &now:target){
            for(auto i:now){
                if(cnt[i]){
                    cnt[i]--;
                }else ans++;
            }
        }
        return ans;
    }
}s;
void mainwork(int T){
    vector<vector<int>> source={{1,2,3},{3,4,5}};
    vector<vector<int>> t={{1,3,5},{2,3,4}};
    printf("%d\n",s.minimumSwitchingTimes(source,t));
}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}