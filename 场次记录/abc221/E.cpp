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

const ll MOD=998244353;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXE=5000050;
const int MAXN=300050;
const int bk_sz=3420;
mt19937 rnd(114514);

ll tr[MAXN<<2],tag[MAXN<<2];
void pushdown(int id){
    if(tag[id]==1)return;
    tag[lc(id)]*=tag[id];
    tag[lc(id)]%=MOD;
    tr[lc(id)]*=tag[id];
    tr[lc(id)]%=MOD;
    tr[rc(id)]*=tag[id];
    tr[rc(id)]%=MOD;
    tag[rc(id)]*=tag[id];
    tag[rc(id)]%=MOD;
    tag[id]=1;
}
ll query(int id,int l,int r,int lb,int rb){
    if(l<=lb&&r>=rb)return tr[id];
    int mid=(lb+rb)>>1;
    pushdown(id);
    ll ans=0;
    if(l<=mid)ans+=query(lc(id),l,r,lb,mid);
    if(r>mid)ans+=query(rc(id),l,r,mid+1,rb);
    return ans%MOD;
}
void modify(int id,int l,int r,int lb,int rb){
    if(l<=lb&&r>=rb){
        tr[id]*=2ll;
        tag[id]*=2ll;
        return;
    }
    pushdown(id);
    int mid=(lb+rb)>>1;
    if(l<=mid)modify(lc(id),l,r,lb,mid);
    if(r>mid)modify(rc(id),l,r,mid+1,rb);
    tr[id]=tr[lc(id)]+tr[rc(id)];
    tr[id]%=MOD;
}
void modify_ps(int id,int pos,int lb,int rb,ll val){
    if(lb>=rb){
        tr[id]+=val;
        tr[id]%=MOD;
        return;
    }
    pushdown(id);
    int mid=(lb+rb)>>1;
    if(pos<=mid)modify_ps(lc(id),pos,lb,mid,val);
    else modify_ps(rc(id),pos,mid+1,rb,val);
    tr[id]=tr[lc(id)]+tr[rc(id)];
    tr[id]%=MOD;
}
int a[MAXN];
vector<int> lsh;
int getid(int val){
    return lower_bound(all(lsh),val)-lsh.begin()+1;
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        lsh.eb(a[i]);
    }
    
    sort(all(lsh));
    lsh.erase(unique(all(lsh)),lsh.end());
    int sz=lsh.size();
    for(int i=1;i<=sz<<2;i++)tag[i]=1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int id=getid(a[i]);
        ll tmp=query(1,1,id,1,sz);
        tag[1]*=2;
        tr[1]*=2;
        modify_ps(1,id,1,sz,1);
        ans+=tmp;
        ans%=MOD;
    }
    printf("%lld\n",ans);
    



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