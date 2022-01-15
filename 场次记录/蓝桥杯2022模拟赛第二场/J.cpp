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

vector<pair<int,int> >G[MAXN];
int dis[MAXN];
bool vis[MAXN];
void dij(int s,int n){
    for(int i=1;i<=n;i++){
        vis[i]=0;
        dis[i]=INF;
    }
    dis[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
    q.push(mkp(0,s));
    while(!q.empty()){
        int now=q.top().second;q.pop();
        if(vis[now])continue;
        vis[now]=1;
        for(auto i:G[now]){
            int to=i.first;
            if(dis[to]>dis[now]+i.second){
                dis[to]=dis[now]+i.second;
                q.push(mkp(dis[to],to));
            }
        }
    }
}
int getid(int x,int y,int m){
    return (x-1)*m+y;
}
char s[MAXN/20][MAXN/20];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int idf=getid(i,j,m);
            if(s[i][j]=='2'){
                int x=i+1,y=j;
                int idt=getid(x,y,m);
                if(x<=n&&s[x][y]!='2'){
                    G[idf].emplace_back(mkp(idt,0));
                    G[idt].emplace_back(mkp(idf,1));
                }
                x=i,y=j+1;
                idt=getid(x,y,m);
                if(y<=m&&s[x][y]!='2'){
                    G[idf].emplace_back(mkp(idt,0));
                    G[idt].emplace_back(mkp(idf,1));
                }
            }else{
                int x=i+1,y=j;
                int idt=getid(x,y,m);
                if(x<=n){
                    if(s[x][y]=='1'){
                        G[idf].emplace_back(mkp(idt,0));
                        G[idt].emplace_back(mkp(idf,0));
                    }else{
                        G[idf].emplace_back(mkp(idt,1));
                        G[idt].emplace_back(mkp(idf,0));
                    }
                }
                x=i,y=j+1;
                idt=getid(x,y,m);
                if(y<=m){
                    if(s[x][y]=='1'){
                        G[idf].emplace_back(mkp(idt,0));
                        G[idt].emplace_back(mkp(idf,0));
                    }else{
                        G[idf].emplace_back(mkp(idt,1));
                        G[idt].emplace_back(mkp(idf,0));
                    }
                }
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         for(auto to:G[getid(i,j,m)]){
    //             printf("%d %d %d\n",getid(i,j,m),to.first,to.second);
    //         }
    //         puts("");
    //     }
    // }
    dij(1,n*m);
    int ans=0;
    ans=vis[getid(n,m,m)]?dis[getid(n,m,m)]:-1;
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