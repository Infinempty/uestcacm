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
const int MAXN=300050;
const int bk_sz=3420;
mt19937 rnd(114514);

vector<pair<int,int> >G[MAXN];
vector<int>lsh;
inline int getid(int val){return lower_bound(all(lsh),val)-lsh.begin()+1;}

pair<int,int> tr[MAXN<<3],tag[MAXN<<3];

//first=max,second=line_id
inline void pushdown(int id){
    if(!tag[id].first)return;
    tr[lc(id)]=max(tr[lc(id)],tag[id]);
    tag[lc(id)]=max(tag[lc(id)],tag[id]);
    tr[rc(id)]=max(tr[rc(id)],tag[id]);
    tag[rc(id)]=max(tag[rc(id)],tag[id]);
    tag[id]=mkp(0,0);
}
void modify(int id,int l,int r,int lb,int rb,pair<int,int> &val){
    if(l<=lb&&r>=rb){
        tag[id]=max(tag[id],val);
        tr[id]=max(tr[id],val);
        return;
    }
    pushdown(id);
    int mid=(lb+rb)>>1;
    if(l<=mid)modify(lc(id),l,r,lb,mid,val);
    if(r>mid)modify(rc(id),l,r,mid+1,rb,val);
    tr[id]=max(tr[lc(id)],tr[rc(id)]);
}
pair<int,int> query(int id,int l,int r,int lb,int rb){
    if(l<=lb&&r>=rb){
        return tr[id];
    }
    pushdown(id);
    pair<int,int> ans=mkp(0,0);
    int mid=(lb+rb)>>1;
    if(l<=mid)ans=max(ans,query(lc(id),l,r,lb,mid));
    if(r>mid)ans=max(ans,query(rc(id),l,r,mid+1,rb));
    return ans;
}
int pre[MAXN],vis[MAXN];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1,x,l,r;i<=m;i++){
        scanf("%d%d%d",&x,&l,&r);
        G[x].eb(mkp(l,r));
        lsh.eb(l),lsh.eb(r);
    }
    sort(all(lsh));
    lsh.erase(unique(all(lsh)),lsh.end());
    for(int i=1;i<=n;i++){
        for(auto &line:G[i]){
            line.first=getid(line.first);
            line.second=getid(line.second);
        }
    }
    int sz=lsh.size();
    for(int i=1;i<=n;i++){
        pair<int,int> now=mkp(0,0);
        for(auto &line:G[i]){
            now=max(now,query(1,line.first,line.second,1,sz));
        }
        pre[i]=now.second;
        now=mkp(now.first+1,i);
        for(auto &line:G[i]){
            modify(1,line.first,line.second,1,sz,now);
        }
    }
    int now=tr[1].second;
    vector<int> ans;
    while(now){
        vis[now]=1;
        now=pre[now];
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])ans.eb(i);
    }
    printf("%d\n",ans.size());
    for(auto now:ans){
        printf("%d ",now);
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