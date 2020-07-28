#include<iostream>
#define ll long long
using namespace std;
const ll PHI=1e9+6;
const ll MOD=1e9+7;
ll mpow(ll a,ll n){
    if(n==0)return 1;
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
ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
void solve(){
    ll n=1,tmp,ans1,ans2,sy=1;
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%lld",&tmp);
        n=(n*(tmp%(PHI)))%(PHI);
    }
    if(n==0){
        printf("500000004/500000004");
        return;
    }
    ans2=mpow(2,n-1);
    if(n%2){
        ans1=ans2-1;
    }else{
        ans1=ans2+1;
    }
    ans1=(ans1*mpow(3,MOD-2))%MOD;
    /*if(ans1!=0){
        do{
            sy=gcd(ans1,ans2);
            ans1/=sy;
            ans2/=sy;
        }while(sy!=1);
    }else{
        ans2=1;
    }*/
    printf("%lld/%lld",ans1,ans2);
    return;
    //printf("%lld",mpow(2,1e9+5));
}

int main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}