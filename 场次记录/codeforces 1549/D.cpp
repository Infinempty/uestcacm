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

int lg[MAXN]={-1};
ll a[MAXN];
ll gcdd[MAXN][20];
void build(int n){
    for(int i=1;i<=n;i++){
        lg[i]=lg[i>>1]+1;
        gcdd[i][0]=a[i];
    }
    for(int j=1;j<=lg[n];j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            gcdd[i][j]=__gcd(gcdd[i][j-1],gcdd[i+(1<<(j-1))][j-1]);
        }
    }
}
ll query(int l,int r){
    int len=lg[r-l+1];
    return __gcd(gcdd[l][len],gcdd[r-(1<<len)+1][len]);
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",a+i);
    }
    for(int i=n-1;i;i--){
        a[i]=abs(a[i]-a[i-1]);
    }
    build(n-1);
    int ans=1;
    for(int i=1;i<n;i++){
        int l=i,r=n-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(query(i,mid)>1)l=mid;
            else r=mid-1;
        }
        if(query(i,l)>1)ans=max(ans,l-i+2);
    }
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