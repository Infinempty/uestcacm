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

char s[MAXN];
char a[2]={'R','B'};
void mainwork(int T){
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    int fst=0;
    for(int i=1;i<=n;i++){
        if(s[i]!='?'){
            fst=i;
            break;
        }
    }
    if(!fst){
        for(int i=1;i<=n;i++){
            printf("%c",i&1?'R':'B');
        }
        puts("");
        return;
    }
    int now=s[fst]=='R'?1:0;
    for(int i=fst-1;i;i--){
        s[i]=a[now];
        now^=1;
    }
    for(int i=fst+1;i<=n;i++){
        if(s[i]!='?')continue;
        if(s[i-1]=='R')s[i]='B';
        else s[i]='R';
    }
    puts(s+1);
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