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
const int MAXN=300050;
const int bk_sz=3420;
mt19937 rnd(114514);

struct node{
    ll x,pos;
    bool dir;
    bool operator <(const node &rhs)const{
        return x<rhs.x;
    }
}a[MAXN];

ll ans[MAXN];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].x);
        a[i].pos=i;
    }
    char opt[2];
    for(int i=1;i<=n;i++){
        scanf("%s",opt);
        if(opt[0]=='R'){
            a[i].dir=1;
        }else a[i].dir=0;
    }
    sort(a+1,a+n+1);
    vector<node>l,r;
    for(int sy=0;sy<2;sy++){
        l.clear();r.clear();
        for(int i=1;i<=n;i++){
            if(a[i].x%2!=sy)continue;
            if(a[i].dir){
                r.pb(a[i]);
            }else{
                if(!r.empty()){
                    ll fin=(a[i].x-r.back().x)/2;
                    ans[a[i].pos]=fin;
                    ans[r.back().pos]=fin;
                    r.pop_back();
                }else if(!l.empty()){
                    ll fin=(a[i].x+l.back().x)/2;
                    ans[a[i].pos]=fin;
                    ans[l.back().pos]=fin;
                    l.pop_back();
                }else {
                    l.pb(a[i]);
                }
            }
        }
        while(r.size()>1){
            node a1=r.back();r.pop_back();
            node a2=r.back();r.pop_back();
            ll fin=(2*m-a1.x-a2.x)/2;
            ans[a1.pos]=fin;
            ans[a2.pos]=fin;
        }
        if(!l.empty()&&!r.empty()){
            ll fin=m+l.back().x+(m-r.back().x);
            fin/=2;
            ans[l.back().pos]=ans[r.back().pos]=fin;
        }else if(!l.empty()){
            ans[l.back().pos]=-1;
        }else if(!r.empty()){
            ans[r.back().pos]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        printf("%lld ",ans[i]);
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