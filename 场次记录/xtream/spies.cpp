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

char opt[10];
int fa[MAXN];
int vis[MAXN];
void mainwork(int T){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    char s;
    int root=1,root2=n+1;
    for(int i=2;i<=n;i++){
        scanf("%c",&s);
        getchar();
        int a;
        scanf("%d",&a);
        fa[i]=a;
    }
    for(int i=2;i<=m;i++){
        scanf("%c",&s);
        getchar();
        int a;
        scanf("%d",&a);
        a+=n;
        fa[i+n]=a;
    }
    getchar();
    while(q--){
        s=getchar();
        int tmp1,tmp2;
        getchar();
        char now=getchar();
        scanf("%d",&tmp1);
        if(now=='B')tmp1+=n;
        getchar();
        now=getchar();
        scanf("%d",&tmp2);
        if(now=='B')tmp2+=n;
        //printf("%d %d\n",tmp1,tmp2);
        if(s=='w'){
            //getchar();
            for(int i=1;i<=n+m;i++)vis[i]=INF;
            int now=tmp1;
            vis[now]=1;
            while(1){
                if(now==1||now==n+1)break;
                if(vis[fa[now]]<vis[now]+1)break;
                vis[fa[now]]=min(vis[fa[now]],vis[now]+1);

                now=fa[now];
            }
            now=tmp2;
            vis[now]=1;
            while(1){
                if(now==1||now==n+1)break;
                if(vis[fa[now]]<vis[now]+1)break;
                vis[fa[now]]=min(vis[fa[now]],vis[now]+1);
                now=fa[now];
            }
            if(vis[1]==INF&&vis[n+1]==INF)puts("NONE");
            else if(vis[1]==INF)printf("BLUE %d\n",vis[n+1]-1);
            else if(vis[n+1]==INF)printf("RED %d\n",vis[1]-1);
            else if(vis[1]<vis[n+1])printf("RED %d\n",vis[1]-1);
            else if(vis[1]>vis[n+1])printf("BLUE %d\n",vis[n+1]-1);
            else printf("TIE %d\n",vis[1]-1);

        }else if(s=='c'){
            fa[tmp1]=tmp2;
        }
        getchar();
    }
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