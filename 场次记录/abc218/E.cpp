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

int fa[MAXN];
int find(int x){
    return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void merge(int x,int y){
    int fax=find(x),fay=find(y);
    fa[fay]=fax;
}
struct E{
    int from,to;
    int val;
    bool operator <(const E &rhs)const{
        return val<rhs.val;
    }
}edges[MAXN];

void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&edges[i].from,&edges[i].to,&edges[i].val);
    }
    sort(edges+1,edges+m+1);
    ll ans=0;
    for(int i=1;i<=m;i++){
        int x=edges[i].from,y=edges[i].to;
        ll val=edges[i].val;
        if(find(x)==find(y)){
            if(val<=0)continue;
            else ans+=val;
        }else{
            merge(x,y);
        }
    }
    printf("%lld\n",ans);
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