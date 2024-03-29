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

int a[MAXN];
map<int,int> mp;
int n;
bool dfs(int now,int sum){
    if(now==n){
        if(abs(sum)==abs(a[n])){
            return true;
        }else return false;
    }
    if(dfs(now+1,sum))return true;
    if(dfs(now+1,sum+a[now]))return true;
    if(dfs(now+1,sum-a[now]))return true;
    return false;
}
void mainwork(int T){
    scanf("%d",&n);
    mp.clear();
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=n;i++){
        swap(a[i],a[n]);
        if(dfs(1,0)){
            puts("YES");
            return;
        }
        swap(a[i],a[n]);
    }
    puts("NO");
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