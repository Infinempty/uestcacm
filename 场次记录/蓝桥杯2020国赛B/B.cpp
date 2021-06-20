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
const int MAXN=5050;
const int bk_sz=3420;
const int d=2500;
mt19937 rnd(114514);

int a[MAXN][MAXN],b[MAXN][MAXN];
int xx[]={0,1,0,-1,0},yy[]={0,0,1,0,-1};
void mainwork(int T){
    int n=5000;
    scanf("%d",&n);
    a[d][d]=1;
    a[2020+d][11+d]=1;
    a[11+d][14+d]=1;
    a[2000+d][2000+d]=1;
    for(int t=1;t<=2020;t++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]){
                    for(int k=0;k<5;k++){
                        b[i+xx[k]][j+yy[k]]=1;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=b[i][j];
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans+=a[i][j];
        }
    }
    printf("%d\n",ans);
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