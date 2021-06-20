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

char s[MAXN][MAXN];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    int cnt[]={-1,-1};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='W'){
                if(cnt[(i+j)&1]==-1){
                    cnt[(i+j)&1]=1;
                    cnt[!((i+j)&1)]=2;
                }
                else if(cnt[(i+j)&1]==2){
                    puts("NO");
                    return;
                }
            }else if(s[i][j]=='R'){
                if(cnt[(i+j)&1]==-1){
                    cnt[(i+j)&1]=2;
                    cnt[!((i+j)&1)]=1;
                }
                else if(cnt[(i+j)&1]==1){
                    puts("NO");
                    return;
                }
            }
        }
    }
    if(cnt[0]==-1){
        cnt[0]=1;
        cnt[1]=2;
    }
    puts("YES");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cnt[(i+j)&1]==1)putchar('W');
            else putchar('R');
        }
        putchar('\n');
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