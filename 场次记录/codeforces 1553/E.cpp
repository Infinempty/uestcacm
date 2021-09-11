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
const int MAXN=300050;
const int bk_sz=3420;
mt19937 rnd(114514);

int a[MAXN],ans[MAXN],b[MAXN];
int fa[MAXN];
int find(int x){
    return fa[x]==x?x:(fa[x]=find(fa[x]));
}
void merge(int x,int y){
    int fax=find(x),fay=find(y);
    fa[fax]=fay;
}
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    ans[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        ans[i]=0;
    }
    for(int i=1;i<=n;i++){
        int tmp=(i-a[i]%n+n)%n;
        //printf("%d ",tmp);
        ans[tmp]++;
    }
    //puts("");
    vector<int> fin;
    for(int i=0;i<n;i++){
        if(n-ans[i]<=2*m){
            for(int j=0;j<=n;j++)fa[j]=j;
            for(int j=1;j<=n;j++){
                int now=(a[j]+i);
                if(now>n)now%=n;
                merge(now,j);
            }
            int tmp=0;
            for(int j=1;j<=n;j++){
                if(find(j)==j)tmp++;
            }
            if(n-tmp<=m)fin.eb(i);
        }
    }
    printf("%d ",fin.size());
    for(auto to:fin){
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