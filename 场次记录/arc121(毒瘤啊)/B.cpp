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

int work(char in){
    if(in=='R')return 1;
    else if(in=='G')return 2;
    else if(in=='B')return 3;
}
vector<ll> a[4];
int tot[4];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    char opt[5];
    ll tmp;
    for(int i=1;i<=n<<1;i++){
        scanf("%lld",&tmp);
        scanf("%s",opt);
        a[work(opt[0])].eb(tmp);
        tot[work(opt[0])]++;
    }
    if(tot[1]%2==0&&tot[2]%2==0&&tot[3]%2==0){
        puts("0");
        return;
    }
    for(int i=1;i<=3;i++){
        sort(all(a[i]));
    }
    vector<int> lk;
    if(!(tot[1]&1)){
        lk.eb(1);lk.eb(2);lk.eb(3);
    }else if(!(tot[2]&1)){
        lk.eb(2);lk.eb(1);lk.eb(3);
    }else if(!(tot[3]&1)){
        lk.eb(3);lk.eb(1);lk.eb(2);
    }
    ll ans=LINF;
    ll minn[3];
    minn[1]=minn[2]=LINF;
    for(auto i:a[lk[1]]){
        int id=lower_bound(all(a[lk[2]]),i)-a[lk[2]].begin();
        if(id<tot[lk[2]])ans=min(ans,abs(i-a[lk[2]][id]));
        if(id>0)ans=min(ans,abs(i-a[lk[2]][id-1]));

        id=lower_bound(all(a[lk[0]]),i)-a[lk[0]].begin();
        if(id<tot[lk[0]])minn[1]=min(minn[1],abs(i-a[lk[0]][id]));
        if(id>0)minn[1]=min(minn[1],abs(i-a[lk[0]][id-1]));
    }
    for(auto i:a[lk[2]]){
        int id=lower_bound(all(a[lk[0]]),i)-a[lk[0]].begin();
        if(id<tot[lk[0]])minn[2]=min(minn[2],abs(i-a[lk[0]][id]));
        if(id>0)minn[2]=min(minn[2],abs(i-a[lk[0]][id-1]));
    }
    printf("%lld",min(ans,minn[1]+minn[2]));
    


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