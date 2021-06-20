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
const int MAXN=100050;
const int bk_sz=3420;
mt19937 rnd(114514);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

ll pri[MAXN],tot;
bool vis[MAXN];
void prework(int n){
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            pri[++tot]=i;
        }
        for(int j=1;j<=tot&&i*pri[j]<=n;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0)break;
        }
    }
}
void mainwork(int T){
    ll a,b,k;
    scanf("%lld%lld%lld",&a,&b,&k);
    ll gcdd=gcd(a,b);
    ll cnta=0,cntb=0,cntg=0;
    ll tmpa=a,tmpb=b,tmpg=gcdd;
    for(int i=1;i<=tot&&pri[i]*pri[i]<=a;i++){
        while(a%pri[i]==0){
            a/=pri[i];
            cnta++;
        }
    }
    for(int i=1;i<=tot&&pri[i]*pri[i]<=b;i++){
        while(b%pri[i]==0){
            b/=pri[i];
            cntb++;
        }
    }
    if(a>1)cnta++;
    if(b>1)cntb++;

    if(tmpa==tmpb){
        if(k>cnta+cntb||k<2)puts("NO");
        else puts("YES");
    }else if(tmpa==tmpg||tmpb==tmpg){
        if(k>cnta+cntb)puts("NO");
        else puts("YES");
    }else{
        if(k>cnta+cntb||k<2)puts("NO");
        else puts("YES");
    }

}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    int t=1;
    prework(MAXN-50);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}