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

int cnt[10];
char s[MAXN];
int np[]={1,4,6,8,9},p[]={2,3,5,7};
int pri[MAXN],tot;
bool vis[MAXN];
void prework(){
    int n=10000;
    for(int i=2;i<=n;i++){
        if(!vis[i]){
            pri[++tot]=i;
        }
        for(int j=1;j<=tot&&i*pri[j]<=n;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0)break;
        }
    }
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=0;i<10;i++)cnt[i]=0;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        int now=s[i]-'0';
        cnt[now]++;
    }
    for(auto now:np){
        if(cnt[now]){
            printf("1\n%d\n",now);
            return;
        }
    }
    for(auto now:p){
        if(cnt[now]>1){
            printf("2\n%d%d\n",now,now);
            return;
        }
    }
    for(int sta=1;sta<(1<<n);sta++){
        int now=0;
        for(int j=0;j<n;j++){
            if((sta>>j)&1){
                now*=10;
                now+=(s[j+1]-'0');
            }
        }
        if(vis[now]){
            printf("%d\n",__builtin_popcount(sta));
            for(int j=0;j<n;j++){
                if((sta>>j)&1){
                    printf("%c",s[j+1]);
                }
            }
            puts("");
            return;
        }
    }
    printf("%d\n",n);
    puts(s+1);
}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    int t=1;
    prework();
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}