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
const ld eps=1e-6;
const int INF=0x3f3f3f3f;
const int MAXE=5000050;
const int MAXN=200050;
const int bk_sz=3420;
mt19937 rnd(114514);

ld v;
ld ans;
void dfs(ld c,ld m,ld p,ld gl,int dep){
    ans+=1.0*dep*gl*p;
    if(c<=eps&&v<=eps){
        return;
    }
    if(c>eps){
        if(c>v){
            if(m>eps){
                ld tmp=v/2.0;
                dfs(c-v,m+tmp,p+tmp,gl*c,dep+1);
            }else{
                dfs(c-v,0,p+v,gl*c,dep+1);
            }
        }else{
            if(m>eps){
                ld tmp=c/2.0;
                dfs(0.0,m+tmp,p+tmp,gl*c,dep+1);
            }else{
                dfs(0,0,1,gl*c,dep+1);
            }
        }
    }
    if(m>eps){
        if(m>v){
            if(c>eps){
                ld tmp=v/2.0;
                dfs(c+tmp,m-v,p+tmp,gl*m,dep+1);
            }else{
                dfs(0,m-v,p+v,gl*m,dep+1);
            }
        }else{
            if(c>eps){
                ld tmp=m/2.0;
                dfs(c+tmp,0.0,p+tmp,gl*m,dep+1);
            }else{
                dfs(0,0,1,gl*m,dep+1);
            }
        }
    }
}
void mainwork(int T){
    ld c,m,p;
    ans=0;
    cin>>c>>m>>p>>v;
    dfs(c,m,p,1,1);
    printf("%.9f\n",ans);
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