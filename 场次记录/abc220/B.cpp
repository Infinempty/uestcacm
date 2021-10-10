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

char a[MAXN],b[MAXN];
void mainwork(int T){
    ll k;
    scanf("%lld",&k);
    scanf("%s",a+1);
    scanf("%s",b+1);
    
    
    int len=strlen(a+1);
    ll aa=0,bb=0;
    for(int i=1;i<=len;i++){
        ll now=a[i]-'0';
        aa+=now;
        aa*=k;
    }
    aa/=k;
    len=strlen(b+1);
    for(int i=1;i<=len;i++){
        ll now=b[i]-'0';
        bb+=now;
        bb*=k;
    }
    bb/=k;
    printf("%lld\n",aa*bb);
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