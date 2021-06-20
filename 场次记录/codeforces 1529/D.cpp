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

const ll MOD=998244353;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXE=5000050;
const int MAXN=1000050;
const int bk_sz=3420;
mt19937 rnd(114514);

int pri[MAXN];
bool vis[MAXN];
ll num[MAXN],d[MAXN];
int tot;
void prework(int n){
    d[1]=1;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            d[i]=2;
            pri[++tot]=i;
            num[i]=1;
        }
        for(int j=1;j<=tot&&i*pri[j]<=n;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0){
                num[i*pri[j]]=num[i]+1;
                d[i*pri[j]]=d[i]/num[i*pri[j]]*(num[i*pri[j]]+1);
                break;
            }else{
                num[i*pri[j]]=1;
                d[i*pri[j]]=d[i]*2;
            }
        }
    }
}

void mainwork(int T){
    int n;
    scanf("%d",&n);
    prework(n);
    ll sum=1;
    if(n==1){
        puts("1");
        return;
    }
    for(int i=2;i<n;i++){
        ll tmp=sum+d[i];
        tmp%=MOD;
        sum+=tmp;
        sum%=MOD;
    }
    printf("%lld\n",(sum+d[n])%MOD);

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