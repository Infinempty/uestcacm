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
const int MAXN=300050;
const int bk_sz=3420;
mt19937 rnd(114514);

char s[MAXN];
bool check(int n,char c){
    for(int i=1;i<=n;i++){
        if(s[i]!=c)return false;
    }
    return true;
}
bool check2(int idx,int n,char c){
    for(int j=idx;j<=n;j+=idx){
        if(s[j]!=c)return false;
    }
    return true;
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    char c[10];
    scanf("%s",c);
    scanf("%s",s+1);
    if(check(n,c[0])){
        puts("0");
        return;
    }
    vector<int> ans;
    bool ok=0;
    for(int i=n;i;i--){
        if(check2(i,n,c[0])){
            ok=1;
            ans.eb(i);
            break;
        }
    }
    if(!ok){
        ans.eb(n);
        ans.eb(n-1);
    }
    printf("%d\n",ans.size());
    for(auto i:ans){
        printf("%d ",i);
    }
    puts("");
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