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
const int MAXN = 2050;
const int bk_sz = 3420;
mt19937 rnd(114514);

struct ST {
    ll a[MAXN];
    int n;
    int lg[MAXN] = { -1 };
    ll maxx[MAXN][15];
    void create_ST() {
        for (int i = 1;i <= n;i++) {
            lg[i] = lg[i / 2] + 1;
            maxx[i][0] = a[i];
            //minn[i][0] = a[i];
        }
        for (int i = 1;i <= lg[n];i++) {
            for (int j = 1;j + (1 << i) - 1 <= n;j++) {
                maxx[j][i] = max(maxx[j][i - 1], maxx[j + (1 << (i - 1))][i - 1]);
                //minn[j][i] = min(minn[j][i - 1], minn[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
    ll query_max(int l, int r) {
        if(r<l)return -1;
        int len = lg[r - l + 1];
        return max(maxx[l][len], maxx[r - (1 << (len)) + 1][len]);
    }
}rrow[2],ccol[2];
//rrow 0表示横着放的空行 1表示横着放的空列
//ccol 0表示竖着放的空行 1表示竖着放的空列
ll a[MAXN][MAXN],sum[MAXN][MAXN];
ll row[MAXN][2],col[MAXN][2];

int xlen,ylen;
int n,m;
ll getsum(int x1, int y1, int x2, int y2) {
    if(x2>n||y2>m)return 0;
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
ll getmax(int x,int y){
    ll tmp=0;
    tmp=rrow[0].query_max(x+1,n-xlen+1);
    tmp=max(tmp,rrow[1].query_max(y+1,m-ylen+1));
    tmp=max(tmp,ccol[0].query_max(x+1,n-ylen+1));
    tmp=max(tmp,ccol[1].query_max(y+1,m-xlen+1));
    return tmp;
}
void mainwork(int T) {
    scanf("%d%d", &n, &m);
    scanf("%d%d", &xlen, &ylen);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",a[i]+j);
            sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+a[i][j];
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int xx=i+xlen-1,yy=j+ylen-1;
            ll tmp=getsum(i,j,xx,yy);
            ans=max(ans,tmp);
            row[i][0]=max(row[i][0],tmp);
            row[j][1]=max(row[j][1],tmp);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int xx=i+ylen-1,yy=j+xlen-1;
            ll tmp=getsum(i,j,xx,yy);
            ans=max(ans,tmp);
            col[i][0]=max(col[i][0],tmp);
            col[j][1]=max(col[j][1],tmp);
        }
    }
    for(int i=1;i<=n;i++){
        rrow[0].a[i]=row[i][0];
        ccol[0].a[i]=col[i][0];
    }
    for(int i=1;i<=m;i++){
        rrow[1].a[i]=row[i][1];
        ccol[1].a[i]=col[i][1];
    }
    rrow[0].n=ccol[0].n=n;
    rrow[1].n=ccol[1].n=m;
    rrow[0].create_ST();
    rrow[1].create_ST();
    ccol[0].create_ST();
    ccol[1].create_ST();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int xx=i+xlen-1,yy=j+ylen-1;
            ll tmp=getsum(i,j,xx,yy);
            ans=max(ans,tmp+getmax(xx,yy));
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int xx=i+ylen-1,yy=j+xlen-1;
            ll tmp=getsum(i,j,xx,yy);
            ans=max(ans,tmp+getmax(xx,yy));
        }
    }
    printf("%lld\n",ans);



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