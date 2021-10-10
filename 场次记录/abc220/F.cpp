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
#define int ll

const ll MOD=1e9+7;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXE=5000050;
const int MAXN=2050;
const int bk_sz=3420;
mt19937 rnd(114514);

vector<int> G[MAXN];
int sz[MAXN],dep[MAXN],st[MAXN],ed[MAXN],f[MAXN];
ll a[MAXN];
ll tr[MAXN<<2],tag[MAXN<<2];
int dfs_clock;
void dfs(int now,int fa,int dp=1){
    st[now]=++dfs_clock;
    dep[now]=dp;
    sz[now]=1;
    f[now]=fa;
    for(auto to:G[now]){
        if(to==fa)continue;
        dfs(to,now,dp+1);
        sz[now]+=sz[to];
    }
    ed[now]=dfs_clock;
}
void build(int id,int lb,int rb){
    if(lb>=rb){
        tr[id]=a[lb];
        tag[id]=0;
        return;
    }
    int mid=(lb+rb)>>1;
    build(lc(id),lb,mid);
    build(rc(id),mid+1,rb);
    tr[id]=tr[lc(id)]+tr[rc(id)];
    tag[id]=0;
}
inline void pushdown(int id,int lb,int rb){
    if(!tag[id])return;
    int mid=(lb+rb)>>1;
    tag[lc(id)]+=tag[id];
    tag[rc(id)]+=tag[id];
    tr[lc(id)]+=1ll*(mid-lb+1)*tag[id];
    tr[rc(id)]+=1ll*(rb-mid)*tag[id];
    tag[id]=0;
    return;
}
void modify(int id,int l,int r,int lb,int rb,ll val){
    if(l<=lb&&r>=rb){
        tr[id]+=1ll*(rb-lb+1)*val;
        tag[id]+=val;
        return;
    }
    pushdown(id,lb,rb);
    int mid=(lb+rb)>>1;
    if(l<=mid)modify(lc(id),l,r,lb,mid,val);
    if(r>mid)modify(rc(id),l,r,mid+1,rb,val);
    tr[id]=tr[lc(id)]+tr[rc(id)];
}
ll query(int id,int pos,int lb,int rb){
    if(lb>=rb){
        return tr[id];
    }
    pushdown(id,lb,rb);
    int mid=(lb+rb)>>1;
    if(pos<=mid)return query(lc(id),pos,lb,mid);
    else return query(rc(id),pos,mid+1,rb);
}
void mainwork(int T){
    int n;
    scanf("%lld",&n);
    for(int i=1,u,v;i<n;i++){
        scanf("%lld%lld",&u,&v);
        G[u].eb(v);
        G[v].eb(u);
    }
    dfs(1,0);
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=1ll*dep[i];
    }
    for(int i=1;i<=n;i++){
        a[st[i]]=1ll*dep[i]*n+sum;
    }
    build(1,1,n);
    for(int i=1;i<=n;i++){
        for(auto to:G[i]){
            if(to==f[i])continue;
            ll nowsz=sz[to]-sz[i];
            nowsz*=2;
            modify(1,st[to],ed[to],1,n,nowsz*dep[i]);
        }
        modify(1,st[i],st[i],1,n,-2ll*sz[i]*dep[i]);
    }
    for(int i=1;i<=n;i++){
        printf("%lld\n",query(1,st[i],1,n));
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