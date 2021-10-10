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

char s1[MAXN],s2[MAXN];
bool vis[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)vis[i]=0;
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        int t1=s1[i]-'0',t2=s2[i]-'0';
        if(t1^t2){
            ans+=2;
            continue;
        }
        if(t1==0){
            ans++;
            continue;
        }
        if(i>1&&!vis[i-1]){
            t1=s1[i-1]-'0',t2=s2[i-1]-'0';
            if(t1==t2&&t1==0){
                ans++;
                continue;
            }
        }
        if(i<n){
            t1=s1[i+1]-'0',t2=s2[i+1]-'0';
            if(t1==t2&&t1==0){
                ans++;
                vis[i+1]=1;
                continue;
            }
        }
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