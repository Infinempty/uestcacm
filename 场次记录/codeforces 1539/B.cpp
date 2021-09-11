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

ll cnt[MAXN][30];
char s[MAXN];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        int now=s[i]-'a'+1;
        cnt[i][now]++;
        for(int j=1;j<=26;j++){
            cnt[i][j]+=cnt[i-1][j];
        }
    }
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        ll ans=0;
        for(int i=1;i<=26;i++){
            ans+=1ll*i*(cnt[r][i]-cnt[l-1][i]);
        }
        printf("%lld\n",ans);
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