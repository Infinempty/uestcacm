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
int cnt[10][2];
void mainwork(int T){
    scanf("%s",s+1);
    int n=strlen(s+1);
    ll ans=0;
    for(int i=1;i<(1<<n)-1;i++){
        memset(cnt,0,sizeof(cnt));
        for(int j=1;j<=n;j++){
            int sta=(i>>(j-1))&1;
            cnt[s[j]-'0'][sta]++;
        }
        ll tmp[2]={0,0};
        for(int j=9;~j;j--){
            while(cnt[j][0]){
                tmp[0]*=10;
                tmp[0]+=j;
                cnt[j][0]--;
            }
            while(cnt[j][1]){
                tmp[1]*=10;
                tmp[1]+=j;
                cnt[j][1]--;
            }
        }
        ans=max(ans,tmp[0]*tmp[1]);
    }
    cout<<ans;
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