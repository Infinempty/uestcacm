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
const int MAXN=2050;
const int bk_sz=3420;
mt19937 rnd(114514);

int dis[MAXN][MAXN];
bool vis[MAXN];
int cnt=0;
bool check(int idx,int n){
    for(int i=1;i<=n;i++){
        if(i==idx)continue;
        if(dis[idx][i]==0)return false;
    }
    vis[idx]=1;
    return true;
}
void query(int idx,int n){
    if(vis[idx])return;
    if(check(idx,n))return;
    vis[idx]=1;
    if(cnt>=(n+1)/2)return;
    printf("? %d\n",idx);
    cnt++;
    fflush(stdout);
    for(int i=1;i<=n;i++){
        scanf("%d",dis[idx]+i);
        dis[i][idx]=dis[idx][i];
    }
}

int fa[MAXN];
bool visq[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    query(1,n);
    int cnt[]={0,0};
    for(int i=2;i<=n;i++){
        cnt[dis[1][i]&1]++;
    }
    int q=cnt[0]>cnt[1];
    for(int i=2;i<=n;i++){
        if(dis[1][i]%2==q){
            query(i,n);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         printf("%d ",dis[i][j]);
    //     }
    //     puts("");
    // }
    printf("!\n");
    set<pair<int,int> >st;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]==1){
                int x=min(i,j),y=max(i,j);
                st.insert(mkp(x,y));
            }
        }
    }
    for(auto i:st){
        printf("%d %d\n",i.first,i.second);
    }
    //system("pause");
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