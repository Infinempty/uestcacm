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


char s[MAXN];
char m[][2]={{'0','0'},{'0','5'},{'5','2'},{'5','7'}};
void mainwork(int T){
    int n;
    scanf("%s",s+1);
    n=strlen(s+1);
    int ans=n;
    for(int t=0;t<4;t++){
        for(int i=n;i;i--){
            if(s[i]!=m[t][0])continue;
            for(int j=i-1;j;j--){
                if(s[j]!=m[t][1])continue;
                ans=min(ans,n-j-1);
            }
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
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}