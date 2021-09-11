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

int a[MAXN][6];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    set<int> st;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            scanf("%d",a[i]+j);
        }
        st.insert(i);
    }
    vector<int> era;
    while(!st.empty()){
        int now=*st.begin();
        era.clear();
        bool ok=0;
        for(auto to:st){
            if(now==to)continue;
            int cnt=0;
            for(int i=1;i<=5;i++){
                cnt+=(a[now][i]<a[to][i]);
            }
            if(cnt>=3){
                era.eb(to);
            }else{
                era.eb(now);
                ok=1;
                break;
            }
        }
        for(auto to:era){
            st.erase(to);
        }
        if(!ok){
            int cnt=0;
            for(int i=1;i<=n;i++){
                int tmp=0;
                for(int j=1;j<=5;j++){
                    tmp+=a[now][j]<a[i][j];
                }
                cnt+=tmp>=3;
            }
            if(cnt==n-1){
                printf("%d\n",now);

            }else puts("-1");
            return;
        }

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