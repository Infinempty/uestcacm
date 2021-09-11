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

int cnt[MAXN][26];
int cnt2[MAXN][26];
int f(char in){
    return in-'a';
}
char s[MAXN];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        for(int j=0;j<26;j++){
            cnt2[i][j]=cnt[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++){
            cnt[j][f(s[j])]++;
        }
    }
    for(int i=1;i<n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++){
            cnt2[j][f(s[j])]++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<26;j++){
            if(cnt[i][j]^cnt2[i][j]){
                printf("%c",'a'+j);
                break;
            }
        }
    }
    puts("");
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