#include<iostream>
#include<unordered_map>
#include<math.h>
#define ll long long
using namespace std;
ll p;
unordered_map<ll,ll> vis;
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y){
    //这玩意也可以求最大公因数，不过还是令写一个gcd更方便吧
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    ll r=exgcd(b,a%b,x,y);
    ll temp=y;
    y=x-(a/b)*y;
    x=temp;
    return r;
}
ll inv(ll a,ll b){
    ll x,y;
    exgcd(a,b,x,y);
    return (x%b+b)%b;
}
ll mpow(ll a,ll n,ll MOD)
{
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
ll BSGS(ll b,ll n,ll p){
    vis.clear();
    ll m=ceil(sqrt(p+0.5));
    n%=p;
    ll now=n,f;
    for(ll i=1;i<=m;i++){
        now=now*(b%p)%p;
        vis[now]=i;
    }
    f=mpow(b,m,p);
    now=1;
    for(ll i=1;i<=m;i++){
        now=now*f%p;
        if(vis[now]){
            return ((i*m%p-vis[now])+p)%p;
        }
    }
    return -1;
}
ll exBSGS(ll b,ll n,ll p){
    if(n==1||p==1)return 0;
    ll d=gcd(b,p);
    ll tmp=1,k=0;
    while(d!=1){
        if(n%d!=0)return -1;
        p/=d,n/=d,tmp=((b/d)*tmp%p)%p,k++;
        if(tmp==n)return k;
        d=gcd(b,p);
    }
    ll ans=BSGS(b,(n*inv(tmp,p))%p,p);
    if(ans==-1)return -1;
    return ans+k;
}
void solve(){
    ll b,n,ans;
    scanf("%lld %lld %lld",&b,&n,&p);
    ans=exBSGS(b,n,p);
    if(ans==-1)printf("QAQ\n");
    else printf("%lld\n",ans);
}

signed main(){
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}