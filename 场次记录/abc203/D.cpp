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

int a[MAXN][MAXN];
int ck[MAXN][MAXN],sum[MAXN][MAXN];
vector<int> lsh;
bool check(int n,int k,int val){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ck[i][j]=a[i][j]<=val;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+ck[i][j];
        }
    }
    for(int i=k;i<=n;i++){
        for(int j=k;j<=n;j++){
            if(sum[i][j]-sum[i][j-k]-sum[i-k][j]+sum[i-k][j-k]>=(k*k)/2+(k&1))return true;
        }
    }
    return false;
}
void mainwork(int T){
    int k,n;
    scanf("%d%d",&n,&k);
    lsh.eb(-1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            lsh.eb(a[i][j]);
        }
    }
    sort(all(lsh));
    // for(auto i:lsh){
    //     printf("%d ",i);
    // }
    // puts("");
    int l=1,r=n*n;
    while(l<r){
        int mid=(l+r)>>1;
        int tmp=lsh[mid];
        if(check(n,k,tmp)){
            r=mid;
        }else l=mid+1;
    }
    printf("%d\n",lsh[l]);
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