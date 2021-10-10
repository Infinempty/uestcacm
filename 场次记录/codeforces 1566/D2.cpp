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
const int MAXN=550;
const int bk_sz=3420;
mt19937 rnd(114514);

int a[MAXN*MAXN];
vector<int> lsh;
int getid(int val){
    return lower_bound(all(lsh),val)-lsh.begin()+1;
}
int pos[MAXN][MAXN];
inline int lowbit(int x){
    return x&(-x);
}
struct BIT{
    ll tr[MAXN];
    void clear(int n){
        for(int i=1;i<=n;i++){
            tr[i]=0;
        }
    }
    void modify(int n,int pos){
        while(pos<=n){
            tr[pos]++;
            pos+=lowbit(pos);
        }
    }
    ll query(int pos){
        ll ans=0;
        while(pos){
            ans+=tr[pos];
            pos-=lowbit(pos);
        }
        return ans;
    }
}tr[MAXN];
set<pair<int,int> > st[MAXN*MAXN];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",a+i);
        lsh.eb(a[i]);
    }
    sort(all(lsh));
    for(int i=1,tot=0;i<=n;i++){
        for(int j=1;j<=m;j++,tot++){
            pos[i][j]=lsh[tot];
        }
        pos[i][m+1]=-1;
    }
    lsh.erase(unique(all(lsh)),lsh.end());
    for(int i=1;i<=n*m;i++)a[i]=getid(a[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            pos[i][j]=getid(pos[i][j]);
        }
    }
    for(int i=1;i<=lsh.size();i++){
        st[i].clear();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int cnt=1,now=pos[i][j];
            while(pos[i][j]==pos[i][j+1]){
                j++;
                cnt++;
            }
            st[now].insert(mkp(i,cnt));
        }
    }
    ll ans=0;
    for(int i=1;i<=n*m;i++){
        pair<int,int> now=*st[a[i]].begin();
        st[a[i]].erase(st[a[i]].begin());
        now.second--;
        ans+=tr[now.first].query(a[i]-pos[now.first][1]);
        tr[now.first].modify(m,a[i]-pos[now.first][1]+1);
        if(now.second){
            st[a[i]].insert(now);
        }
    }
    printf("%lld\n",ans);
    lsh.clear();
    for(int i=1;i<=n;i++){
        tr[i].clear(m);
    }

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