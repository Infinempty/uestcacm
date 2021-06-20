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

int a[MAXN];
bool vis[MAXN];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
ll cnt[2];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    cnt[0]=cnt[1]=0;
    vector<int> odd;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        vis[i]=0;
        cnt[a[i]&1]++;
        if(a[i]&1)odd.eb(a[i]);
    }
    ll ans=(cnt[0]-1)*cnt[0]/2+cnt[0]*cnt[1];
    for(int i=0;i<odd.size();i++){
        for(int j=i+1;j<odd.size();j++){
            if(gcd(odd[i],odd[j])>1)ans++;
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