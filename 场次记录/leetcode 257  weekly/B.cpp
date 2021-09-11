//#pragma GCC target("avx2")
//#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr)
#define all(x) x.begin(),x.end()
#define pb push_back
#define eb emplace_back
#define mkp make_pair
#define lc(x) ((x)<<1)
#define rc(x) (((x)<<1)|1)

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


//num[n] num[y0] 
vector<int>G[MAXN];
class Solution {
public:
    int tr[MAXN<<2],tag[MAXN<<2];
    void pushdown(int id){
        if(!tag[id])return;
        tr[lc(id)]=0;
        tr[rc(id)]=0;
        tag[lc(id)]=1;
        tag[rc(id)]=1;
        tag[id]=0;
    }
    void modify_ps(int id,int pos,int lb,int rb){
        if(lb>=rb){
            tr[id]++;
            return;
        }
        pushdown(id);
        int mid=(lb+rb)>>1;
        if(pos<=mid)modify_ps(lc(id),pos,lb,mid);
        else modify_ps(rc(id),pos,mid+1,rb);
        tr[id]=tr[lc(id)]+tr[rc(id)];
    }
    void clear(int id,int l,int r,int lb,int rb){
        if(l<=lb&&r>=rb){
            tr[id]=0;
            tag[id]=1;
            return;
        }
        pushdown(id);
        int mid=(lb+rb)>>1;
        if(l<=mid)clear(lc(id),l,r,lb,mid);
        if(r>mid)clear(rc(id),l,r,mid+1,rb);
        tr[id]=tr[lc(id)]+tr[rc(id)];
    }
    int query(int id,int l,int r,int lb,int rb){
        if(l<=lb&&r>=rb){
            return tr[id];
        }
        pushdown(id);
        int ans=0,mid=(lb+rb)>>1;
        if(l<=mid)ans+=query(lc(id),l,r,lb,mid);
        if(r>mid)ans+=query(rc(id),l,r,mid+1,rb);
        return ans;
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=100000;
        for(int i=1;i<=n<<2;i++)tr[i]=tag[i]=0;
        for(int i=1;i<=n;i++)G[i].clear();
        for(auto &i:properties){
            G[i[0]].eb(i[1]);
            //G[1]
        }
        for(int i=1;i<=n;i++)sort(all(G[i]));
        // for(auto it:G){
        //     printf("%d %d\n",it.first,it.second);
        // }
        int ans=0;
        for(int i=1;i<=n;i++){

            for(auto now:G[i]){
                //x=i,y=now
                if(now>1){
                    ans+=query(1,1,now-1,1,n);
                    clear(1,1,now-1,1,n);
                }
            }
            for(auto now:G[i]){
                modify_ps(1,now,1,n);
            }
            
        }
        return ans;
    }
}S;


int sol(){
    vector<pair<int,int> > num;
    sort(all(num));
    int ans=0;
    int count[MAXN];
    for(int i=0;i<num.size();i++){
        for(int j=1;j<num[i].second;j++){
            ans+=count[j];
        }
        for(int j=1;j<num[i].second;j++){
            count[j]=0;
        }
        count[num[i].second]++;
    }
    return ans;
}

void mainwork(int T){
    vector<vector<int>> nums={{1,1},{2,1},{2,2},{1,2}};
    printf("%d\n",S.numberOfWeakCharacters(nums));
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