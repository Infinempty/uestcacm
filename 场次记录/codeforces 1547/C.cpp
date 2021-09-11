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

void mainwork(int T){
    int n,m,k;
    scanf("%d%d%d",&k,&n,&m);
    queue<int> q[2];
    for(int i=1,tmp;i<=n;i++){
        scanf("%d",&tmp);
        q[0].push(tmp);
    }
    for(int i=1,tmp;i<=m;i++){
        scanf("%d",&tmp);
        q[1].push(tmp);
    }
    vector<int> ans;
    while(!q[0].empty()&&!q[1].empty()){
        if(q[0].front()==0){
            ans.eb(0);k++;
            q[0].pop();
        }else if(q[1].front()==0){
            ans.eb(0);k++;
            q[1].pop();
        }else if(q[0].front()<=k){
            ans.eb(q[0].front());
            q[0].pop();
        }else if(q[1].front()<=k){
            ans.eb(q[1].front());
            q[1].pop();
        }else{
            puts("-1");
            return;
        }
    }
    while(!q[0].empty()){
        if(q[0].front()<=k){
            ans.eb(q[0].front());
            if(q[0].front()==0)k++;
            q[0].pop();
        }else {
            puts("-1");
            return;
        }
    }
    while(!q[1].empty()){
        if(q[1].front()<=k){
            ans.eb(q[1].front());
            if(q[1].front()==0)k++;
            q[1].pop();
        }else {
            puts("-1");
            return;
        }
    }
    for(auto to:ans){
        printf("%d ",to);
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