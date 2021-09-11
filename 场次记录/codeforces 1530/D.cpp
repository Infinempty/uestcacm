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

int vis[MAXN];
int ans[MAXN];
int a[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ans[i]=vis[i]=0;
    }
    int fin=0;
    for(int i=1,tmp;i<=n;i++){
        scanf("%d",&a[i]);
        if(!vis[a[i]]){
            vis[a[i]]=i;
            ans[i]=a[i];
            fin++;
        }
    }
    vector<int> unget,unsend;
    for(int i=1;i<=n;i++){
        if(!vis[i])unget.eb(i);
        if(!ans[i])unsend.eb(i);
    }
    int lst=0;
    for(int i=0;i<unget.size();i++){
        if(unget[i]==unsend[i]&&i==unget.size()-1){
            lst=unget[i];
            break;
        }else if(unget[i]==unsend[i]){
            swap(unget[i],unget[i+1]);
        }
        vis[unget[i]]=unsend[i];
        ans[unsend[i]]=unget[i];
    }
    if(lst){
        ans[lst]=a[lst];
        ans[vis[a[lst]]]=lst;
    }
    printf("%d\n",fin);
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
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