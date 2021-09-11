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
void mainwork(int T){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s",s+1);
    if(b>=0){
        printf("%d\n",n*(a+b));
        return;
    }
    int ans=n*a;
    int cnt[2]={0,0};
    for(int i=1;i<=n;){
        int now=i;
        while(s[now+1]==s[now]){
            now++;
        }
        cnt[s[now]-'0']++;
        i=now+1;
    }
    ans+=(min(cnt[0],cnt[1])+1)*b;
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