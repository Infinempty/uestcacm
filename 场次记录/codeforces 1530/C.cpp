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

int a[2][MAXN],sum[2][MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a[0]+i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",a[1]+i);
    }
    sort(a[0]+1,a[0]+n+1);
    sort(a[1]+1,a[1]+n+1);
    for(int i=0;i<2;i++){
        for(int j=1;j<=n;j++){
            sum[i][j]=sum[i][j-1]+a[i][j];
        }
    }
    for(int t=0;;t++){
        int sq=(t+n)/4;
        int sum1=sum[0][n]-sum[0][sq]+t*100;
        int sq2=max(0,(t+n)/4-t);
        int sum2=sum[1][n]-sum[1][sq2];
        //printf("t %d:%d %d\n",t,sum1,sum2);
        if(sum1>=sum2){
            printf("%d\n",t);
            return;
        }
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