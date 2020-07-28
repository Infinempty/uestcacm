#include<iostream>
#define ll long long
#define int long long
using namespace std;
ll divis[20000],cnt[20000];
int tmp=0;
ll prime[10]={2,3,5,7,11,13,17,19,23,29};
ll k=1e18,n,ans1,ans2;
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
bool is_prime(ll x){
    int i,j,k;
    int s=0,t=x-1;
    if(x==2)  return true;
    if(x<2||!(x&1))  return false;
    while(!(t&1))
    {
        s++;
        t>>=1;
    }
    for(i=0;i<10&&prime[i]<x;++i)
    {
        int a=prime[i];
        int b=mpow(a,t,x);
        for(j=1;j<=s;++j)
        {
            k=(b*b)%x;
            if(k==1&&b!=1&&b!=x-1)
                return false;
            b=k;
        }
        if(b!=1)  return false;
    }
    return true;
}
void dives(ll n){
    ll t=n;
    for(ll i=2;i<=n;i++){
        if(n%i==0){
            divis[++tmp]=1;
            cnt[tmp]=0;
            while (n%i==0) {
                cnt[tmp]++;
                divis[tmp]*=i;
                n /= i;
            }
        }
        if(is_prime(n)){
            divis[++tmp]=n;
            cnt[tmp]=1;
            break;
        }
    }
}
ll exgcd(ll a,ll b,ll &x,ll &y){
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
void dfs(int dep,ll now){
    if(k==1)return;
    ll a=now,b,tmp1,tmp2,tmp3;
    if(dep==tmp){
        b=n/a;
        exgcd(a,b,tmp1,tmp2);
        while(tmp1==0||tmp2==0){
            tmp1+=b;
            tmp2-=a;
        }
        tmp2=-tmp2;
        tmp3=tmp1*tmp2;
        if(tmp2>=0&&tmp1>=0){
            if(k>tmp3&&tmp3>0){
                ans1=a*tmp1;
                ans2=b*tmp2;
                k=tmp3;
            }
        }
        a*=divis[dep];
        b/=divis[dep];
        exgcd(a,b,tmp1,tmp2);
        while(tmp1==0||tmp2==0){
            tmp1+=b;
            tmp2-=a;
        }
        tmp2=-tmp2;
        tmp3=tmp1*tmp2;
        if(tmp2>=0&&tmp1>=0){
            if(k>tmp3&&tmp3>0){
                ans1=a*tmp1;
                ans2=b*tmp2;
                k=tmp3;
            }
        }
        return;
    }
    dfs(dep+1,now*divis[dep]);
    dfs(dep+1,now);
}
void solve(){
    ll t1=0,t2=0,a=1,b;
    k=1e18;
    tmp=0;
    divis[0]=1;
    cnt[0]=0;
    scanf("%lld",&n);
    n*=2;
    dives(n);
    b=n;
    dfs(1,1);
    printf("%lld\n",ans1-1);
}

signed main(){
    int t=1;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }

    return 0;
}