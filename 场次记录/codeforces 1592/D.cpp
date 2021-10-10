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
const int MAXN=10050;
const int bk_sz=3420;
mt19937 rnd(114514);

int query(set<int> &x){
    printf("? %d ",x.size());
    for(auto i:x){
        printf("%d ",i);
    }
    puts("");
    fflush(stdout);
    int ans;
    scanf("%d",&ans);
    return ans;
}

int ord[MAXN],dfs_clock,tot;
int head[MAXN];
struct E{
    int from,to,nxt;
}edges[MAXN];
void addedge(int u,int v){
    edges[++tot].from=u;
    edges[tot].to=v;
    edges[tot].nxt=head[u];
    head[u]=tot;
}
void dfs(int now,int fa){
    for(int i=head[now];~i;i=edges[i].nxt){
        int to=edges[i].to;
        if(to==fa)continue;
        ord[++dfs_clock]=i;
        dfs(to,now);
        ord[++dfs_clock]=i;
    }
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)head[i]=-1;
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    dfs(1,0);
    int l=1,r=2*n-2;
    set<int> st;
    for(int i=1;i<=n;i++)st.insert(i);
    int sum=query(st);
    while(l<r){
        int mid=(l+r)>>1;
        st.clear();
        for(int i=l;i<=mid;i++){
            st.insert(edges[ord[i]].from);
            st.insert(edges[ord[i]].to);
        }
        int tmp=query(st);
        if(tmp==sum)r=mid;
        else l=mid+1;
    }
    printf("! %d %d",edges[ord[l]].from,edges[ord[l]].to);
    fflush(stdout);
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