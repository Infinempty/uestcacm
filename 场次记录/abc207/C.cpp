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

struct L{
    int t,l,r;
    bool operator<(const L &rhs)const{
        return l<rhs.l;
    }
}a[MAXN];

void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].t,&a[i].l,&a[i].r);
        a[i].l=a[i].l*2+1,a[i].r=a[i].r*2-1;
        if(a[i].t==1||a[i].t==2)a[i].l--;
        if(a[i].t==1||a[i].t==3)a[i].r++;
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        //printf("%d %d %d\n",a[i].t,a[i].l,a[i].r);
        for(int j=1;j<i;j++){
            if(a[i].l<=a[j].r)ans++;
        }
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
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}