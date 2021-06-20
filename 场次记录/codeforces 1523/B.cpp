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

struct node{
    int a,b,c;
};
void mainwork(int T){
    int n;
    scanf("%d",&n);
    vector<node> ans;
    for(int i=1,tmp;i<=n;i++){
        scanf("%d",&tmp);
    }
    for(int i=1;i<=n;i+=2){
        ans.pb({1,i,i+1});
        ans.pb({1,i,i+1});
        ans.pb({2,i,i+1});
        ans.pb({1,i,i+1});
        ans.pb({1,i,i+1});
        ans.pb({2,i,i+1});
    }
    printf("%d\n",ans.size());
    for(auto now:ans){
        printf("%d %d %d\n",now.a,now.b,now.c);
    }
}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}