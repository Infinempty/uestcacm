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
const int MAXN=400050;
const int bk_sz=3420;
mt19937 rnd(114514);

int fa[MAXN],sz[MAXN];
int find(int x){
    return x==fa[x]?x:(fa[x]=find(fa[x]));
}
void merge(int x,int y){
    int fax=find(x),fay=find(y);
    if(fax==fay)return;
    sz[fax]+=sz[fay];
    fa[fay]=fax;
}
int vis[MAXN];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n<<1;i++){
        fa[i]=i;
        sz[i]=i>n?1:0;
        vis[i]=0;
    }
    char opt[10];
    for(int i=1,x,y;i<=m;i++){
        scanf("%d%d",&x,&y);
        scanf("%s",opt);
        if(opt[0]=='c'){
            merge(x,y);
            merge(x+n,y+n);
        }else if(opt[0]=='i'){
            merge(x,y+n);
            merge(x+n,y);
        }
    }
    for(int i=1;i<=n;i++){
        if(find(i)==find(i+n)){
            puts("-1");
            return;
        }
    }
    int ans=0;
    for(int i=1;i<=n<<1;i++){
        int fax=find(i),fay=find(i+n);
        if(vis[fax])continue;
        vis[fax]=vis[fay]=1;
        ans+=max(sz[fax],sz[fay]);
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
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}