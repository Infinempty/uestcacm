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
int a[MAXN];
int cnt[MAXN*10];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    int t=(1<<m)-1;
    for(int i=0;i<=t;i++)cnt[i]=0;
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        int now=0;
        for(int i=1;i<=m;i++){
            if(s[i]=='y')now++;
            now<<=1;
        }
        now>>=1;
        a[i]=now;
        for(int s=now;s;s=(s-1)&now){
            cnt[s]++;
        }
    }
    // for(int i=1;i<=t;i++){
    //     printf("%d ",cnt[i]);
    // }
    puts("");
    cnt[0]=n-2;
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int now=a[i]|a[j];
            now^=t;
            ans+=cnt[now];
        }
    }
    printf("%lld\n",ans/3);
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