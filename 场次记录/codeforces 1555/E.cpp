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
const int MAXE=1000050;
const int MAXN=300050;
const int bk_sz=3420;
mt19937 rnd(114514);

struct L{
    int l,r,cost;
    bool operator <(const L &rhs)const{
        return cost<rhs.cost;
    }
}line[MAXN];

int tr[MAXE<<2],tag[MAXE<<2];
inline void pushdown(int id){
    if(!tag[id])return;
    tr[lc(id)]+=tag[id];
    tr[rc(id)]+=tag[id];
    tag[lc(id)]+=tag[id];
    tag[rc(id)]+=tag[id];
    tag[id]=0;
    return;
}
void modify(int id,int l,int r,int lb,int rb,int val){
    if(l<=lb&&r>=rb){
        tr[id]+=val;
        tag[id]+=val;
        return;
    }
    pushdown(id);
    int mid=(lb+rb)>>1;
    if(l<=mid)modify(lc(id),l,r,lb,mid,val);
    if(r>mid)modify(rc(id),l,r,mid+1,rb,val);
    tr[id]=min(tr[lc(id)],tr[rc(id)]);
}

void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&line[i].l,&line[i].r,&line[i].cost);
        line[i].r--;
    }
    sort(line+1,line+n+1);
    int l=1,r=0;
    int ans=INF;
    for(int l=1,r=1;r<=n;r++){
        modify(1,line[r].l,line[r].r,1,m-1,1);
        while(tr[1]){
            ans=min(ans,line[r].cost-line[l].cost);
            modify(1,line[l].l,line[l].r,1,m-1,-1);
            if(tr[1])l++;
            else{
                modify(1,line[l].l,line[l].r,1,m-1,1);
                break;
            }
        }
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
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}