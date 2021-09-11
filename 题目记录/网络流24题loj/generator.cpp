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

void mainwork(int T){
    //generator 从.out中读数据 输出到.in
    // 1<=n<=2e5 1<=m<=2e5 0<=a[i]<=1e9+7 1<=l<=r<=n 0<=val<=1e9+7
    int n,m;
    scanf("%d%d",&n,&m);
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++){
        int tmp=rnd();
        tmp=abs(tmp)%MOD;
        printf("%d ",tmp);
    }
    puts("");
    while(m--){
        int opt,l,r;
        ll val;
        opt=rnd();
        if(opt&1){
            int l=1,r=n;
            ll val=1;
            if(l>r)swap(l,r);
            printf("%d %d %d %lld\n",1,l,r,val);
        }else{
            int l=1,r=n;
            if(l>r)swap(l,r);
            printf("2 %d %d\n",l,r);
        }
    }
}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.out","r",stdin);
    freopen("Ranulx.in","w",stdout);
#endif
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}