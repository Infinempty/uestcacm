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
int tr[MAXN];
inline int lowbit(int x){return x&(-x);}
void modify(int idx,int n){
    while(idx<=n){
        tr[idx]++;
        idx+=lowbit(idx);
    }
}
int query(int idx){
    int ans=0;
    while(idx){
        ans+=tr[idx];
        idx-=lowbit(idx);
    }
    return ans;
}

bool vis[MAXN];
vector<int> lsh;
inline int getid(int val){return lower_bound(all(lsh),val)-lsh.begin()+1;}

void mainwork(int T){
    int n;
    scanf("%d",&n);
    lsh.clear();
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        lsh.eb(a[i]);
        tr[i]=0;
    }
    sort(all(lsh));
    lsh.erase(unique(all(lsh)),lsh.end());
    modify(getid(a[1]),n);
    for(int i=2;i<=n;i++){
        int pre=max(a[i-1],a[i]),now=min(a[i-1],a[i]);
        if(query(getid(pre)-1)>query(getid(now))){
            puts("NO");
            return;
        }
        modify(getid(a[i]),n);
    }
    puts("YES");
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