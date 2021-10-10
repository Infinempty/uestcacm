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
#define int ll

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

ll dp[MAXN];
char s[MAXN];
signed work(){
    if(s[1]=='w')return 0;
    else if(s[1]=='y')return 1;
    else if(s[1]=='g')return 2;
    else if(s[1]=='b')return 3;
    else if(s[1]=='r')return 4;
    else if(s[1]=='o')return 5;
}
int highbit(int x){
    int ans=0;
    while(x){
        ans++;
        x>>=1;
    }
    return ans;
}

void mainwork(int T){
    int k;
    scanf("%lld",&k);
    dp[1]=1;
    for(int i=2;i<=k;i++){
        dp[i]=(dp[i-1]*dp[i-1])%MOD*16%MOD;
    }
    int m;
    scanf("%d",&m);
    map<pair<ll,ll> ,ll> mp;
    map<ll,ll> col,vis;
    priority_queue<ll> q;
    for(int i=1;i<=m;i++){
        ll n;
        scanf("%lld",&n);
        scanf("%s",s+1);
        int t=work();
        col.insert(mkp(n,t));
        q.push(n);
    }
    while(!q.empty()){
        ll now=q.top();q.pop();
        if(!now)break;
        if(vis.count(now))continue;
        int cnt=vis.count(lc(now))+vis.count(rc(now));
        vis.insert(mkp(now,1));
        if(cnt==0){
            for(int i=0;i<6;i++){
                mp.insert(mkp(mkp(now,i),0));
            }
            int t=k-highbit(now)+1;
            mp[mkp(now,col[now])]=dp[t];
            q.push(now/2);
            continue;
        }else if(cnt==1){
            if(vis.count(lc(now))){
                for(int i=0;i<6;i++){
                    ll tmp=0;
                    for(int j=0;j<6;j++){
                        if(i/2==j/2)continue;
                        int t=k-highbit(lc(now))+1;
                        tmp+=mp[(mkp(lc(now),j))]*dp[t]%MOD*4%MOD;
                        tmp%=MOD;
                    }
                    mp[mkp(now,i)]+=tmp;
                    mp[mkp(now,i)]%=MOD;
                }
            }else{
                for(int i=0;i<6;i++){
                    ll tmp=0;
                    for(int j=0;j<6;j++){
                        if(i/2==j/2)continue;
                        int t=k-highbit(rc(now))+1;
                        tmp+=mp[(mkp(rc(now),j))]*dp[t]%MOD*4%MOD;
                        tmp%=MOD;
                    }
                    mp[mkp(now,i)]+=tmp;
                    mp[mkp(now,i)]%=MOD;
                }
            }
        }else{
            for(int i=0;i<6;i++){
                ll tmp=0;
                for(int j=0;j<6;j++){
                    if(i/2==j/2)continue;
                    for(int k=0;k<6;k++){
                        if(i/2==k/2)continue;
                        tmp+=mp[mkp(lc(now),j)]*mp[mkp(rc(now),k)]%MOD;
                        tmp%=MOD;
                    }
                }
                mp[mkp(now,i)]+=tmp;
                mp[mkp(now,i)]%=MOD;
            }
        }
        if(col.count(now)){
            for(int i=0;i<6;i++){
                if(i==col[now])continue;
                mp[mkp(now,i)]=0;
            }
        }
        q.push(now/2);
    }
    ll ans=0;
    if(!vis.count(1)){
        ans=dp[k]*6%MOD;
    }else{
        for(int i=0;i<6;i++){
            ans+=mp[mkp(1,i)];
            ans%=MOD;
        }
    }
    printf("%lld\n",ans);
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