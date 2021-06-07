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

char in[MAXN];
vector<int> q[5];
int st[5],per[5];
inline int work(char in){
    if(in=='A')return 1;
    else if(in=='T')return 2;
    else if(in=='O')return 3;
    else if(in=='N')return 4;
    return 5;
}
inline char rev(int in){
    if(in==1)return 'A';
    else if(in==2)return 'T';
    else if(in==3)return 'O';
    else if(in==4)return 'N';
    return 'Z';
}
int tr[MAXN<<2],tag[MAXN<<2];
inline void pushup(int id){
    tr[id]=tr[lc(id)]+tr[rc(id)];
}
inline void add(int id,int val,int lb,int rb){
    tag[id]+=val;
    tr[id]+=(rb-lb+1)*val;
}
void pushdown(int id,int lb,int rb){
    if(!tag[id])return;
    int mid=(lb+rb)>>1;
    add(lc(id),tag[id],lb,mid);
    add(rc(id),tag[id],mid+1,rb);
    tag[id]=0;
}
int query(int id,int pos,int lb,int rb){
    if(lb>=rb)return tr[id];
    int mid=(lb+rb)>>1;
    pushdown(id,lb,rb);
    if(pos<=mid)return query(lc(id),pos,lb,mid);
    if(pos>mid)return query(rc(id),pos,mid+1,rb);
} 
void modify(int id,int l,int r,int lb,int rb,int val){
    if(l<=lb&&r>=rb){
        add(id,val,lb,rb);
        return;
    }
    pushdown(id,lb,rb);
    int mid=(lb+rb)>>1;
    if(l<=mid)modify(lc(id),l,r,lb,mid,val);
    if(r>mid)modify(rc(id),l,r,mid+1,rb,val);
    pushup(id);
}

void mainwork(int T){
    scanf("%s",in+1);
    int n=strlen(in+1);
    for(int i=1;i<=4;i++){
        q[i].clear();
    }
    for(int i=1;i<=n;i++){
        q[work(in[i])].eb(i);
    }
    
    for(int i=1;i<=4;i++)per[i]=i;
    int sum=1,idx=0;
    ll ans=0,tmp;
    for(int p=0;p<24;p++){
        tmp=0;
        sum=1;
        for(int i=1;i<=n<<2;i++)tr[i]=tag[i]=0;
        for(int i=1;i<=4;i++){
            st[per[i]]=sum;
            sum+=q[per[i]].size();
        }
        for(int i=1;i<=4;i++){
            for(int j=0;j<q[per[i]].size();j++){
                int now=q[per[i]][j],to=st[per[i]]+j,nnow=q[per[i]][j]+query(1,now,1,n);
                tmp+=abs(nnow-to);
                modify(1,1,now,1,n,1);
            }
        }
        if(tmp>ans){
            ans=tmp;
            idx=p;
        }
        // for(int i=1;i<=4;i++){
        //     printf("%c",rev(per[i]));
        // }
        // printf(": %lld\n",tmp);
        next_permutation(per+1,per+5);
    }
    for(int i=1;i<=4;i++)per[i]=i;
    for(int p=0;p<idx;p++)next_permutation(per+1,per+5);
    for(int i=1;i<=4;i++){
        for(int j=1;j<=q[per[i]].size();j++){
            printf("%c",rev(per[i]));
        }
    }
    puts("");
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