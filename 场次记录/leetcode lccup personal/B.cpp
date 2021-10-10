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
    int sum[MAXN][2];
    int maxmiumScore(vector<int>& cards, int cnt) {
        vector<int> nums[2];
        for(auto i:cards){
            nums[i&1].emplace_back(i);
        }      
        sort(all(nums[0]),greater<int>{});
        sort(all(nums[1]),greater<int>{});
        sum[0][0]=sum[0][1]=0;
        int n[2]={nums[0].size(),nums[1].size()};
        for(int now=0;now<2;now++){
            for(int i=1;i<=n[now];i++){
                sum[i][now]=sum[i-1][now]+nums[now][i-1];
            }
        }
        bool ok=0;
        int ans=0;
        for(int i=0;i<=cnt;i++){
            int odd=i,even=cnt-i;
            if(odd>n[1]||even>n[0])continue;
            int tmp=sum[odd][1]+sum[even][0];
            if(tmp&1)continue;
            ok=1;
            ans=max(ans,tmp);
        }
        return ans;

    }
}s;

void mainwork(int T){
    vector<int> now={3,3,1};
    int cnt=2;
    printf("%d\n",s.maxmiumScore(now,cnt));
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