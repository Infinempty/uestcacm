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

void mainwork(int T){
    multiset<int> st;
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=1,tmp;i<=n;i++){
        scanf("%d",&tmp);
        if(sum+tmp>=0){
            st.insert(tmp);
            sum+=1ll*tmp;
        }else {
            if(tmp>*st.begin()){
                sum-=1ll*(*st.begin());
                st.erase(st.begin());
                sum+=tmp;
                st.insert(tmp);
            }
        }
    }
    printf("%d\n",st.size());
}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    int t=1;
    // scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}