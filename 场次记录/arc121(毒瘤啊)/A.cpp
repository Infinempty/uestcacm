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

multiset<pair<int,int> > stx,sty;
int x[MAXN],y[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",x+i,y+i);
        stx.insert(mkp(x[i],i));
        sty.insert(mkp(y[i],i));
    }
    vector<int> v;
    if(n<=10){
        for(int i=1;i<=n;i++){
            v.eb(i);
        }
    }else{
        set<int> st;
        for(int i=1;i<=2;i++){
            auto maxx=*stx.rbegin();
            auto minn=*stx.begin();
            st.insert(maxx.second);
            stx.erase(stx.begin());
            stx.erase(stx.find(maxx));
            st.insert(minn.second);
            maxx=*sty.rbegin();
            minn=*sty.begin();
            st.insert(maxx.second);
            st.insert(minn.second);
            sty.erase(sty.begin());
            sty.erase(sty.find(maxx));
        }
        for(auto i:st){
            v.eb(i);
        }
    }
    vector<int> dis;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            dis.eb(max(abs(x[v[i]]-x[v[j]]),abs(y[v[i]]-y[v[j]])));
        }
    }
    sort(all(dis),greater<>{});
    printf("%d\n",dis[1]);

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