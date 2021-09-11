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

ll mpow(ll a,ll n){
    ll ans=1;
    while(n){
        if(n&1){
            ans*=a;
        }
        a*=a;
        n>>=1;
    }
    return ans;
}
ll pos[100];
void mainwork(int T){
    ll s,n;
    scanf("%lld%lld",&s,&n);
    int cnt=0;
    ll tmp=s;
    while(tmp){
        cnt++;
        tmp/=10;
    }
    tmp=s;
    for(int i=1;i<=cnt;i++){
        pos[i]=tmp%10;
        tmp/=10;
    }
    vector<ll> ans;
    for(int i=cnt;i>1;i--){
        while(pos[i]){
            if(n==1)break;
            tmp=mpow(10,i-1);
            if(s-tmp<n-1){
                pos[i-1]+=pos[i]*10;
                pos[i]=0;
                break;
            }
            pos[i]--;
            ans.eb(tmp);
            s-=tmp;
            n--;
        }
        if(n==1)break;
    }
    if(n==1){
        tmp=0;
        for(int i=1;i<=cnt;i++){
            tmp+=pos[i]*mpow(10,i-1);
        }
        ans.eb(tmp);
        n--;
    }
    else if(pos[1]>n){
        ans.eb(pos[1]-n+1);
        n--;
    }
    for(int i=1;i<=n;i++)ans.eb(1);
    for(auto i:ans){
        printf("%lld ",i);
    }
    puts("");

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