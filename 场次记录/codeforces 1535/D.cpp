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
const int MAXN=1000050;
const int bk_sz=3420;
mt19937 rnd(114514);

int fa[MAXN],sum[MAXN],ls[MAXN],rs[MAXN];
bool root[MAXN];
char sta[MAXN];
char s[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    n=(1<<n)-1;
    int tot=n-1;
    for(int i=1;i<=n;i++){
        root[i]=0;
        ls[i]=rs[i]=0;
        sum[i]=0;
        sta[i]=s[i];
    }
    fa[n]=0;
    for(int i=n;i;i--){
        if(tot){
            rs[i]=tot;
            fa[tot--]=i;
            ls[i]=tot;
            fa[tot--]=i;
        }else{
            root[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(root[i]){
            if(s[i]=='?')sum[i]=2;
            else sum[i]=1;
        }else{
            if(s[i]=='?')sum[i]=sum[ls[i]]+sum[rs[i]];
            if(s[i]=='0')sum[i]=sum[ls[i]];
            if(s[i]=='1')sum[i]=sum[rs[i]];
        }
    }
    // for(int i=n;i;i--){
    //     printf("%d %d %d\n",ls[i],rs[i],fa[i]);

    // }
    int m;
    char opt[2];
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int now;
        scanf("%d",&now);
        scanf("%s",opt);
        if(root[now]){
            if(opt[0]=='?')sum[now]=2;
            else sum[now]=1;
        }else{
            if(opt[0]=='?')sum[now]=sum[ls[now]]+sum[rs[now]];
            else if(opt[0]=='0')sum[now]=sum[ls[now]];
            else if(opt[0]=='1')sum[now]=sum[rs[now]];
        }
        sta[now]=opt[0];
        now=fa[now];
        while(now){
            if(sta[now]=='?')sum[now]=sum[ls[now]]+sum[rs[now]];
            else if(sta[now]=='0')sum[now]=sum[ls[now]];
            else if(sta[now]=='1')sum[now]=sum[rs[now]];
            now=fa[now];
        }
        printf("%d\n",sum[n]);
    }
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