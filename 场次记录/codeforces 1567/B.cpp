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

int xo[MAXN];
void prework(int n){
    xo[0]=0;
    for(int i=1;i<=n;i++){
        xo[i]=xo[i-1]^i;
    }
}
void mainwork(int T){
    int a,b;
    scanf("%d%d",&a,&b);
    int sum=0;
    sum=xo[a-1];
    int tmp=sum^b;
    if(tmp==0){
        printf("%d\n",a);
    }else if(tmp!=a){
        printf("%d\n",a+1);
    }else{
        printf("%d\n",a+1+1);
    }


}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    prework(300000);
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}