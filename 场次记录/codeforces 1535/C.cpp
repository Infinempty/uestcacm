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
ll dp[MAXN][2];
void mainwork(int T){
    scanf("%s",s+1);
    int n=strlen(s+1);
    ll ans=0;
    dp[0][0]=dp[0][1]=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            dp[i][1]=dp[i-1][0]+1;
            dp[i][0]=0;
        }else if(s[i]=='0'){
            dp[i][1]=0;
            dp[i][0]=dp[i-1][1]+1;
        }else{
            dp[i][1]=dp[i-1][0]+1;
            dp[i][0]=dp[i-1][1]+1;
        }
    }
    for(int i=1;i<=n;){
        if(s[i]!='?'){
            i++;
            continue;
        }
        int idx=i;
        while(s[idx+1]=='?')idx++;
        ans-=1ll*(1ll*idx-i+1)*(1ll*idx-i+2)/2ll;
        i=idx+1;
        
    }
    for(int i=1;i<=n;i++){
        ans+=dp[i][1];
        ans+=dp[i][0];
    }
    printf("%lld\n",ans);

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