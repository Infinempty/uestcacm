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

char s[MAXN],t[MAXN];

void mainwork(int T){
    scanf("%s",s+1);
    scanf("%s",t+1);
    int n1=strlen(s+1),n2=strlen(t+1);
    string tt;
    for(int i=1;i<=n2;i++){
        tt.pb(t[i]);
    }
    string ans;
    for(int i=1;i<=n1;i++){
        if(s[i]==t[1]){
            for(int j=i;j<=n1;j++){
                if(s[j]==t[j-i+1]){
                    int len=j-i+1;
                    ans.clear();
                    for(int k=i;k<=j;k++){
                        ans.pb(s[k]);
                    }
                    for(int k=j-1;len<n2&&k;len++,k--){
                        ans.pb(s[k]);
                    }
                    if(ans==tt){
                        puts("YES");
                        return;
                    }
                }
            }
        }
    }
    puts("NO");
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