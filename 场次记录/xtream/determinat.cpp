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
const int MAXN=2050;
const int bk_sz=3420;
mt19937 rnd(114514);

int a[MAXN];
ll now[MAXN];
int mat[MAXN][MAXN];
void add(int x,int y,int n){
    for(int i=1;i<=n;i++){
        mat[y][i]+=mat[x][i];
    }
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        mat[i][i]=1;
        now[i]=1ll<<(i-1);
    }
    vector<int> tmp;
    bool ok=0;
    for(int i=1;i<=n;i++){
        ok=0;
        for(ll x=0;x<=(1ll<<(n))-1;x++){
            if((x>>(i-1))&1)continue;
            ll t=now[i];
            tmp.clear();
            for(int j=1;j<=n;j++){
                if((x>>(j-1))&1){
                    t^=now[j];
                    tmp.emplace_back(j);
                }
            }
            if(__builtin_popcountll(t)==a[i]){
                now[i]=t;
                for(auto j:tmp){
                    add(j,i,n);
                }
                ok=1;
                break;
            }
        }
        if(!ok){
            puts("-1");
            return;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",mat[i][j]);
        }
        puts("");
    }
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