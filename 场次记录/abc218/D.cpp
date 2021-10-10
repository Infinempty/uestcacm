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

vector<pair<int,int> >a;
void mainwork(int T){
    int n;
    scanf("%d",&n);
    set<pair<int,int> >st;
    for(int i=1,x,y;i<=n;i++){
        scanf("%d%d",&x,&y);
        st.insert(mkp(x,y));
        a.eb(mkp(x,y));
    }
    sort(all(a));
    int ans=0;
    for(int i=0;i<a.size();i++){
        for(int j=i+1;j<a.size();j++){
            if(a[i].first>=a[j].first||a[i].second>=a[j].second)continue;
            pair<int,int> a1=mkp(a[i].first,a[j].second);
            pair<int,int> a2=mkp(a[j].first,a[i].second);
            if(st.find(a1)==st.end()||st.find(a2)==st.end())continue;
            ans++;
        }
    }
    printf("%d\n",ans);
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