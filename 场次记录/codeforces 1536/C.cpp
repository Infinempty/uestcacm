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
const int MAXN=500050;
const int bk_sz=3420;
mt19937 rnd(114514);

map<pair<int,int>,int > mp;
char s[MAXN];
int ans[MAXN];
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    scanf("%s",s+1);
    int cntd=0,cntk=0;
    mp.clear();
    for(int i=1;i<=n;i++){
        if(s[i]=='D')cntd++;
        else cntk++;
        int gcdd=gcd(cntd,cntk);
        if(mp.count(mkp(cntd/gcdd,cntk/gcdd))){
            ans[i]=mp[mkp(cntd/gcdd,cntk/gcdd)]+1;
            mp[mkp(cntd/gcdd,cntk/gcdd)]++;
        }else{
            ans[i]=1;
            mp.insert(mkp(mkp(cntd/gcdd,cntk/gcdd),1));
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
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