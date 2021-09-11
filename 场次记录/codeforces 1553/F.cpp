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

struct segment_tree{
    ll tr[MAXN<<2],tag[MAXN<<2];
    inline void pushdown(int id,int lb,int rb){
        if(!tag[id])return;
        int mid=(lb+rb)>>1;
        tr[lc(id)]+=tag[id]*(mid-lb+1);
        tr[rc(id)]+=tag[id]*(rb-mid);
        tag[lc(id)]+=tag[id];
        tag[rc(id)]+=tag[id];
        tag[id]=0;
    }
    void modify(int id,int l,int r,int lb,int rb,ll val){
        if(l<=lb&&r>=rb){
            tr[id]+=val*(rb-lb+1);
            tag[id]+=val;
            return;
        }
        pushdown(id,lb,rb);
        int mid=(lb+rb)>>1;
        if(l<=mid)modify(lc(id),l,r,lb,mid,val);
        if(r>mid)modify(rc(id),l,r,mid+1,rb,val);
        tr[id]=tr[lc(id)]+tr[rc(id)];
    }
    ll query(int id,int l,int r,int lb,int rb){
        if(l<=lb&&r>=rb){
            return tr[id];
        }
        pushdown(id,lb,rb);
        ll ans=0;
        int mid=(lb+rb)>>1;
        if(l<=mid)ans+=query(lc(id),l,r,lb,mid);
        if(r>mid)ans+=query(rc(id),l,r,mid+1,rb);
        return ans;
    }
}A,B;

void mainwork(int T){
    int n;
    scanf("%d",&n);
    ll tmp,ans=0,sum=0;
    int sz=300050;
    for(int i=1;i<=n;i++){
        scanf("%lld",&tmp);
        ans+=sum;
        sum+=tmp;
        ans+=tmp*(i-1)-A.query(1,tmp,tmp,1,sz);
        for(ll j=1;j*tmp<=sz;j++){
            A.modify(1,j*tmp,min(1ll*sz,j*tmp+tmp-1),1,sz,j*tmp);
            ans-=B.query(1,j*tmp,min(1ll*sz,j*tmp+tmp-1),1,sz)*j*tmp;
        }
        B.modify(1,tmp,tmp,1,sz,1);
        printf("%lld\n",ans);
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