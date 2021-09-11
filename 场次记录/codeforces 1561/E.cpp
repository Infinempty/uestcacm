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

int a[MAXN];
int find(int n,int val){
    for(int i=1;i<=n;i++){
        if(a[i]==val)return i;
    }
    return 0;
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    if(n%2==0){
        if(a[n]!=n){
            puts("-1");
            return;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i%2!=a[i]%2){
            puts("-1");
            return;
        }
    }
    if(n%2==0)n--;
    vector<int> ans;
    for(int now=n;now>1;now-=2){
        int idx1=find(n,now);
        ans.eb(idx1);
        reverse(a+1,a+idx1+1);
        idx1=find(n,now-1);
        ans.eb(idx1-1);
        reverse(a+1,a+idx1);
        ans.eb(idx1+1);
        reverse(a+1,a+idx1+2);
        idx1=find(n,now);
        ans.eb(idx1);
        reverse(a+1,a+idx1+1);
        ans.eb(now);
        reverse(a+1,a+now+1);
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