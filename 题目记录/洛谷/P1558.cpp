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

int tr[MAXN<<2],tag[MAXN<<2];
void pushdown(int id){
    if(!tag[id])return;
    tr[lc(id)]=tag[id];
    tr[rc(id)]=tag[id];
    tag[lc(id)]=tag[id];
    tag[rc(id)]=tag[id];
    tag[id]=0;
}
void modify(int id,int l,int r,int lb,int rb,int val){
    if(l<=lb&&r>=rb){
        tr[id]=val;
        tag[id]=val;
        return;
    }
    pushdown(id);
    int mid=(lb+rb)>>1;
    if(l<=mid)modify(lc(id),l,r,lb,mid,val);
    if(r>mid)modify(rc(id),l,r,mid+1,rb,val);
    tr[id]=tr[lc(id)]|tr[rc(id)];
}
int query(int id,int l,int r,int lb,int rb){
    if(l<=lb&&r>=rb){
        return tr[id];
    }
    pushdown(id);
    int ans=0,mid=(lb+rb)>>1;
    if(l<=mid)ans|=query(lc(id),l,r,lb,mid);
    if(r>mid)ans|=query(rc(id),l,r,mid+1,rb);
    return ans;
}
void mainwork(int T){
    int n,t,o;
    scanf("%d%d%d",&n,&t,&o);
    char opt[5];
    for(int i=1;i<=(n<<2);i++)tr[i]=1;
    while(o--){
        scanf("%s",opt);
        if(opt[0]=='C'){
            int l,r,val;
            scanf("%d%d%d",&l,&r,&val);
            if(l>r)swap(l,r);
            val=(1<<(val-1));
            modify(1,l,r,1,n,val);
        }else{
            int l,r;
            scanf("%d%d",&l,&r);
            if(l>r)swap(l,r);
            int ans=__builtin_popcount(query(1,l,r,1,n));
            printf("%d\n",ans);
        }
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