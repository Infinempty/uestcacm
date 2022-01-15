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

int sum[MAXN*10][2];
char s[MAXN*10];
void mainwork(int T){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++){
        sum[i][0]=sum[i-1][0];
        sum[i][1]=sum[i-1][1];
        if(s[i]=='['||s[i]==']'){
            sum[i][i&1]++;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d%d",&l,&r);
        int ans=abs(sum[r][0]-sum[l-1][0]-sum[r][1]+sum[l-1][1]);
        printf("%d\n",ans);
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