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
const int MAXE=2000050;
const int MAXN=200050;
const int bk_sz=3420;
mt19937 rnd(114514);

map<int,int> son[MAXE];
ll suf[20];
ll a[20][MAXN],c[20];
int ban[20],tot,root;
ll ans;
int n;
vector<int> fin,tmp;
void insert(int &now,int dep=1){
    
    if(!now){
        now=++tot;
    }
    if(dep>n)return;
    insert(son[now][ban[dep]],dep+1);
}

void dfs(int now,int dep=1,ll sum=0){
    if(!now){
        ll tmp1=sum+suf[dep];
        if(tmp1>ans){
            ans=tmp1;
            fin=tmp;
            for(int i=dep;i<=n;i++){
                fin.emplace_back(c[i]);
            }
        }
        return;
    }
    if(dep>n){
        return;
    }
    int maxx=c[dep];
    for(auto to:son[now]){
        tmp.emplace_back(to.first);
        //maxx=max(maxx,to.first);
        dfs(to.second,dep+1,sum+a[dep][to.first]);
        tmp.pop_back();
    }
    while(son[now].count(maxx)){
        maxx--;
    }
    if(maxx){
        tmp.emplace_back(maxx);
        dfs(0,dep+1,sum+a[dep][maxx]);
        tmp.pop_back();
    }
}
void mainwork(int T){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",c+i);
        for(int j=1;j<=c[i];j++){
            scanf("%lld",&a[i][j]);
        }
    }
    for(int i=n;i;i--){
        ll now=a[i][c[i]];
        suf[i]=suf[i+1]+now;
    }
    suf[n+1]=0;
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",ban+j);
        }
        insert(root);
    }
    dfs(root);
    //printf("%lld\n",ans);
    for(auto i:fin){
        printf("%d ",i);
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