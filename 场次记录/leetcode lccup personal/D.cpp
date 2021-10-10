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
struct Node{
	int l,r;
	int val,key;
	int sz;
};
class Solution {
public:
    Node tr[MAXN];
    int tot,root[MAXN];
    int newnode(int val){
        tr[++tot].val=val;
        tr[tot].sz=1;
        tr[tot].key=rnd();
        return tot;
    }
    void update(int now){
        tr[now].sz=tr[tr[now].l].sz+tr[tr[now].r].sz+1;
        return;
    }
    void spilt(int now,int val,int &x,int &y){
        if(!now){
            x=y=0;
            return;
        }
        if(tr[now].val<=val){
            x=now;
            spilt(tr[now].r,val,tr[now].r,y);
        }else{
            y=now;
            spilt(tr[now].l,val,x,tr[now].l);
        }
        update(now);
    }
    int merge(int x,int y){
        if(!x||!y)return x+y;
        if(tr[x].key>tr[y].key){
            tr[x].r=merge(tr[x].r,y);
            update(x);
            return x;
        }else{
            tr[y].l=merge(x,tr[y].l);
            update(y);
            return y;
        }
    }
    void insert(int &root,int val){
        int x,y;
        spilt(root,val,x,y);
        root=merge(merge(x,newnode(val)),y);
    }
    vector<int> lsh;
    int getid(int val){
        return lower_bound(all(lsh),val)-lsh.begin()+1;
    }
    int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {
        for(auto &now:circles){
            lsh.eb(now[0]);
        }
        sort(all(lsh));
        lsh.erase(unique(all(lsh)),lsh.end());
        for(int i=1;i<=lsh.size();i++)root[i]=0;
        for(auto &now:circles){
            insert(root[getid(now[0])],now[1]);
        }
        int ans=0;
        for(auto &now:toys){
            if(now[2]>r)continue;
            ll t=r-now[2];
            for(ll x=now[0]-t;x<=now[0]+t;x++){
                int id=getid(x);
                if(lsh[id-1]!=x)continue;
                ll upx=sqrtl(1.0*t*t-1.0*(x-now[0])*(x-now[0])+0.5);
                ll dox=now[1]-upx;
                upx+=now[1];
                int r1=0,r2=0,r3=0;
                spilt(root[id],dox-1,r1,r2);
                spilt(r2,upx,r2,r3);
                if(r2){
                    ans++;
                    root[id]=merge(merge(r1,r2),r3);
                    break;
                }
                root[id]=merge(merge(r1,r2),r3);
            }
        }
        return ans;

    }
};



void mainwork(int T){

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