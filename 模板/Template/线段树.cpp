//区间加 区间求和
#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100010;
ll a[maxn];
struct Node
{
    int l,r;
    ll sum,lazy;
}tree[4*maxn];
void build(int x,int l,int r)
{
    tree[x].l=l,tree[x].r=r;
    if(l==r){
        tree[x].sum=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(2*x,l,mid);
    build(2*x+1,mid+1,r);
    tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
    return;
}
void push_down(int x)
{
    if(tree[x].lazy){
        tree[2*x].sum+=tree[x].lazy*(tree[2*x].r-tree[2*x].l+1);
        tree[2*x+1].sum+=tree[x].lazy*(tree[2*x+1].r-tree[2*x+1].l+1);
        tree[2*x].lazy+=tree[x].lazy;
        tree[2*x+1].lazy+=tree[x].lazy;
        tree[x].lazy=0;
    }
    return;
}
void add(int x,int l,int r,ll k)
{
    if(l<=tree[x].l && r>=tree[x].r){
        tree[x].sum+=k*(tree[x].r-tree[x].l+1);
        tree[x].lazy+=k;
        return;
    }
    push_down(x);
    int mid=(tree[x].l+tree[x].r)>>1;
    if(l<=mid) add(2*x,l,r,k);
    if(r>mid) add(2*x+1,l,r,k);
    tree[x].sum=tree[2*x].sum+tree[2*x+1].sum;
}
ll query(int x,int l,int r)
{
    if(l<=tree[x].l && r>=tree[x].r) return tree[x].sum;
    push_down(x);
    int mid=(tree[x].l+tree[x].r)>>1;
    ll ans=0;
    if(l<=mid) ans+=query(2*x,l,r);
    if(r>mid) ans+=query(2*x+1,l,r);
    return ans;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op,x,y;
        ll k;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%lld",&x,&y,&k);
            add(1,x,y,k);
        }
        else{
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,x,y));
        }
    }
    return 0;
}

//区间乘 区间加 区间求和
#include<bits/stdc++.h>
using namespace std;
int p;
long long a[100007];
struct Node
{
    long long v,mul,add;
}st[400007];
void bt(int root,int l,int r)
{
    st[root].mul=1;
    st[root].add=0;
    if(l==r) st[root].v=a[l];
    else{
        int m=(l+r)/2;
        bt(root*2,l,m);
        bt(root*2+1,m+1,r);
        st[root].v=st[root*2].v+st[root*2+1].v;
    }
    st[root].v%=p;
    return;
}
void pushdown(int root,int l,int r)
{
    int m=(l+r)/2;
    st[root*2].v=(st[root*2].v*st[root].mul+st[root].add*(m-l+1))%p;
    st[root*2+1].v=(st[root*2+1].v*st[root].mul+st[root].add*(r-m))%p;
    st[root*2].mul=(st[root*2].mul*st[root].mul)%p;
    st[root*2+1].mul=(st[root*2+1].mul*st[root].mul)%p;
    st[root*2].add=(st[root*2].add*st[root].mul+st[root].add)%p;
    st[root*2+1].add=(st[root*2+1].add*st[root].mul+st[root].add)%p;
    st[root].mul=1;
    st[root].add=0;
    return;
}
void ud1(int root,int stdl,int stdr,int l,int r,long long k)
{
    if(r<stdl || stdr<l) return;
    if(l<=stdl && stdr<=r){
        st[root].v=(st[root].v*k)%p;
        st[root].mul=(st[root].mul*k)%p;
        st[root].add=(st[root].add*k)%p;
        return;
    }
    pushdown(root, stdl, stdr);
    int m=(stdl+stdr)/2;
    ud1(root*2,stdl,m,l,r,k);
    ud1(root*2+1,m+1,stdr,l,r,k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return;
}
void ud2(int root,int stdl,int stdr,int l,int r,long long k)
{
    if(r<stdl || stdr<l) return;
    if(l<=stdl && stdr<=r){
        st[root].add=(st[root].add+k)%p;
        st[root].v=(st[root].v+k*(stdr-stdl+1))%p;
        return;
    }
    pushdown(root,stdl,stdr);
    int m=(stdl+stdr)/2;
    ud2(root*2,stdl,m,l,r,k);
    ud2(root*2+1,m+1,stdr,l,r,k);
    st[root].v=(st[root*2].v+st[root*2+1].v)%p;
    return;
}
long long query(int root,int stdl,int stdr,int l,int r)
{
    if(r<stdl || stdr<l) return 0;
    if(l<=stdl && stdr<=r) return st[root].v;
    pushdown(root,stdl,stdr);
    int m=(stdl+stdr)/2;
    return (query(root*2,stdl,m,l,r)+query(root*2+1,m+1,stdr,l,r))%p;
}
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    bt(1,1,n);
    while(m--){
        int chk;
        scanf("%d",&chk);
        int x,y;
        long long k;
        if(chk==1){
            scanf("%d%d%lld",&x,&y,&k);
            ud1(1,1,n,x,y,k);
        }
        else if(chk==2){
            scanf("%d%d%lld",&x,&y,&k);
            ud2(1,1,n,x,y,k);
        }
        else{
            scanf("%d%d",&x,&y);
            printf("%lld\n",query(1,1,n,x,y));
        }
    }
    return 0;
}