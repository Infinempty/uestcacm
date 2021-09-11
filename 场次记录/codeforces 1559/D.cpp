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

int fa[MAXN][2];
int find(int x,int id){
    return fa[x][id]==x?x:(fa[x][id]=find(fa[x][id],id));
}
void merge(int x,int y,int id){
    int fax=find(x,id);
    int fay=find(y,id);
    fa[fax][id]=fay;
}

bool vis[MAXN][2];
void mainwork(int T){
    int n,m[2];
    scanf("%d%d%d",&n,&m[0],&m[1]);
    for(int i=1;i<=n;i++){
        fa[i][0]=fa[i][1]=i;
    }
    for(int id=0;id<2;id++){
        for(int i=1,x,y;i<=m[id];i++){
            scanf("%d%d",&x,&y);
            merge(x,y,id);
        }
    }
    vector<pair<int,int> >ans;
    for(int i=2;i<=n;i++){
        if(find(1,0)!=find(i,0)&&find(1,1)!=find(i,1)){
            ans.eb(mkp(1,i));
            merge(1,i,0);
            merge(1,i,1);
        }
    }
    vis[find(1,0)][0]=1;
    vis[find(1,1)][1]=1;
    int p1=2,p2=2;
    while(1){
        while(vis[find(p1,0)][0])p1++;
        while(vis[find(p2,1)][1])p2++;
        if(p1>n||p2>n)break;
        if(find(p1,0)!=find(p2,0)&&find(p1,1)!=find(p2,1)){
            merge(p1,p2,0);
            merge(p1,p2,1);
            vis[find(p1,0)][0]=1;
            vis[find(p1,1)][1]=1;
            ans.eb(mkp(p1,p2));
        }
    }
    printf("%d\n",ans.size());
    for(auto now:ans){
        printf("%d %d\n",now.first,now.second);
    }
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