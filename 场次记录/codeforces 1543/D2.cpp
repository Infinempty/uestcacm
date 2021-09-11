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

struct bigint{
    int dig[100];
    int kth;
    int getval(){
        int ans=0;
        int now=1;
        for(int i=0;i<100;i++){
            ans+=now*dig[i];
            now*=kth;
        }
        return ans;
    }
    void init(int k,int val){
        kth=k;
        for(int i=0;i<100;i++)dig[i]=0;
        for(int i=0;i<100&&val;i++){
            dig[i]=val%kth;
            val/=kth;
        }
    }
    void axor(bigint &k){
        for(int i=0;i<100;i++){
            dig[i]+=k.dig[i];
            dig[i]%=kth;
        }
    }
    void inv(){
        for(int i=0;i<100;i++){
            dig[i]=(kth-dig[i])%kth;
        }
    }
};
void mainwork(int T){
    bigint sum,now;
    int k,n;
    scanf("%d%d",&n,&k);
    //sum.init(k,0);
    int tmp;
    for(int i=0;i<n;i++){
        now.init(k,i);
        if(i)sum.init(k,i-1);
        if(i&1){
            now.inv();
            now.axor(sum);
        }else if(i){
            sum.inv();
            now.axor(sum);
        }
        printf("%d\n",now.getval());
        fflush(stdout);
        scanf("%d",&tmp);
        if(tmp)break;
        //sum.axor(now);
        //printf("%d\n",sum.getval());
    }
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