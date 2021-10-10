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

class Solution {
public:
    int a[MAXN],fa[MAXN],top[MAXN],sz[MAXN],son[MAXN],dep[MAXN],st[MAXN],ed[MAXN];
    int dfs_clock,pos[MAXN];
    vector<int>G[MAXN];
    void dfs1(int now,int f){
        dep[now]=dep[f]+1;
        fa[now]=f;
        sz[now]=1;
        for(auto to:G[now]){
            if(to==f)continue;
            dfs1(to,now);
            sz[now]+=sz[to];
            if(sz[son[now]]<sz[to]){
                son[now]=to;
            }
        }
    }
    void dfs2(int now,int head){
        st[now]=++dfs_clock;
        pos[dfs_clock]=now;
        top[now]=head;
        if(!son[now]){
            ed[now]=++dfs_clock;
            pos[dfs_clock]=now;
            return;
        }
        dfs2(son[now],head);
        for(auto to:G[now]){
            if(to==fa[now]||to==son[now])continue;
            dfs2(to,to);
        }
        ed[now]=++dfs_clock;
        pos[dfs_clock]=now;
    }
    int lca(int a,int b){
        while(top[a]!=top[b]){
            if(dep[top[a]]<dep[top[b]])swap(a,b);
            a=fa[top[a]];
        }
        return dep[a]<dep[b]?a:b;
    }
    int rev[MAXN],ans[MAXN];
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        for(int i=1;i<parents.size();i++){
            G[i+1].eb(parents[i]+1);
            G[parents[i]+1].emplace_back(i+1);
        }
        for(int i=1;i<=100001;i++)rev[i]=-1;
        for(int i=0;i<nums.size();i++){
            rev[nums[i]]=i+1;
            ans[i+1]=0;
        }
        dfs1(1,0);
        dfs2(1,1);
        int now=rev[1];
        vector<int> re;
        //for(int i=1;i<=parents.s)
        if(now==-1){
            for(int i=0;i<nums.size();i++){
                re.emplace_back(1);
            }
            return re;
        }
        for(int i=2;now!=1;i++){
            int nxt=rev[i];
            if(nxt==-1)break;
            nxt=lca(nxt,now);
            while(now!=nxt){
                ans[now]=i-1;
                now=fa[now];
            }
            ans[now]=i;
        }
        for(int i=1;i<=100000+20;i++){
            if(rev[i]==-1){
                ans[1]=i-1;
                break;
            }
        }
        for(int i=1;i<=parents.size();i++){
            re.emplace_back(ans[i]+1);
        }
        return re;
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