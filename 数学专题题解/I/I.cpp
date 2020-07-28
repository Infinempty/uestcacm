#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll inv[1000005],ce[1000005];
ll num[1000005],sum[1000005],div_prime[1000005],sum2[1000005];
bool vis[1000005];
vector<ll>prime;
ll mpow(ll a,ll n){
    ll ans=1;
    a%=MOD;
    while(n!=0)
    {
        if(n&1)ans=(ans*a)%MOD;
        n>>=1;
        a=(a*a)%MOD;
    }
    return ans%MOD;
}
void get_prime(){
    for(ll i=2;i<=1000000;i++){
        if(!vis[i]){
            prime.push_back(i);
            div_prime[i]=1;
            num[i]=2;
        }
        for(ll p:prime){
            if(i*p>1000000)break;
            vis[i*p]=1;
            if(i%p==0){
                num[i*p]=num[i]/(div_prime[i]+1)*(div_prime[i]+2);
                div_prime[i*p]=div_prime[i]+1;
                break;
            }else{
                num[i*p]=num[i]*num[p];
                div_prime[i*p]=1;
            }
        }
    }
}
void solve(){
    inv[1]=1;
    ce[1]=1;
    for(ll i=2;i<=1000000;i++){
        inv[i]=(mpow(i,MOD-2)+inv[i-1])%MOD;
        ce[i]=((i*inv[i])%MOD+ce[i-1])%MOD;
    }
    get_prime();
    sum[1]=1;
    sum2[1]=1;
    for(int i=2;i<=1000000;i++){
        sum[i]=(num[i]+sum[i-1])%MOD;
        sum2[i]=(sum[i]+sum2[i-1])%MOD;
    }
    int T,l,r;
    ll ans=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&l,&r);
        ans=1ll*(ce[r]-ce[l-1]+MOD-(sum2[r]-sum2[l-1])+MOD)%MOD;
        printf("%lld\n",ans);
    }

}

int main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}