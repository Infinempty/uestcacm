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
const int MAXN=1050;
const int bk_sz=3420;
mt19937 rnd(114514);

ll dp[MAXN][20];
char s[MAXN][MAXN];
int work(int x,int y){
    if(x==0)return y-1;
    else if(x==1)return x+y+4;
    else if(x==2)return x+y+6;
    else return x+y+7;
}
bool check(int i,int j){
    if(i>j)swap(i,j);
    bool ans=1;
    if(i==2&&j==6)ans=0;
    if(i==3&&j==10)ans=0;
    if(i==4&&j==13)ans=0;
    if(i==5&&j==15)ans=0;
    if(i==6&&j>=6&&j<=9)ans=0;
    if(i==7&&j==10)ans=0;
    if(i==8&&j==13)ans=0;
    if(i==9&&j==15)ans=0;
    if(i==10&&j>=10&&j<=12)ans=0;
    if(i==11&&j==13)ans=0;
    if(i==12&&j==15)ans=0;
    if(i==13&&j==14)ans=0;
    if(i==14&&j==15)ans=0;
    if(i==15&&j==15)ans=0;
    return ans;
}
int check2(int n){
    if(n==1||n==6||n==10||n==13||n==15)return 1;
    return 2;
}
void mainwork(int T){
    int n,m,c;
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    dp[0][1]=1;
    for(int i=1;i<=m;i++){
        if(s[1][i]=='.'&&s[2][i]=='.'){
            for(int t=6;t<=15;t++){
                for(int j=1;j<=15;j++){
                    if(!check(t,j))continue;
                    dp[i][t]+=dp[i-1][j]*check2(j)%MOD;
                    dp[i][t]%=MOD;
                }
            }
        }else if(s[1][i]=='#'&&s[2][i]=='.'){
            for(int t=2;t<=5;t++){
                for(int j=1;j<=15;j++){
                    if(!check(t,j))continue;
                    dp[i][t]+=dp[i-1][j]*check2(j)%MOD;
                    dp[i][t]%=MOD;
                }
            }
        }else if(s[1][i]=='.'&&s[2][i]=='#'){
            for(int t=2;t<=5;t++){
                for(int j=1;j<=15;j++){
                    if(!check(t,j))continue;
                    dp[i][t]+=dp[i-1][j]*check2(j)%MOD;
                    dp[i][t]%=MOD;
                }
            }
        }else{
            for(int j=1;j<=15;j++){
                dp[i][1]+=dp[i-1][j]*check2(j)%MOD;
                dp[i][1]%=MOD;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=15;i++){
        ans+=dp[m][i];
        ans%=MOD;
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
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}