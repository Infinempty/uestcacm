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
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    set<int> lb,rb,st;
    for(int i=1;i<=n;i++){
        st.insert(i);
    }
    lb.insert(l);rb.insert(r);
    st.erase(st.find(l));st.erase(st.find(r));
    for(int i=1;i<n/2;i++){
        rb.insert(*st.begin());
        st.erase(st.begin());
    }
    if(!st.empty()&&*st.begin()<l){
        puts("-1");
        return;
    }
    if(*rb.rbegin()>r){
        puts("-1");
        return;
    }
    for(int i=1;i<n/2;i++){
        lb.insert(*st.begin());
        st.erase(st.begin());
    }
    while(!lb.empty()){
        printf("%d ",*lb.begin());
        lb.erase(lb.begin());
    }
    while(!rb.empty()){
        printf("%d ",*rb.begin());
        rb.erase(rb.begin());
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