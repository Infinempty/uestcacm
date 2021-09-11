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
const int MAXN=100050;
const int bk_sz=3420;
mt19937 rnd(114514);

int tag[MAXN<<2],tr[MAXN<<2];
pair<int,int> a[MAXN];


void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n<<2;i++)tag[i]=tr[i]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+n+1);
    a[n+1].first=-1;
    int cnt[2]={0,0},cnt1[2];
    for(int i=1;i<=n;){
        int l=i,r=i;
        while(a[r].first==a[r+1].first)r++;
        cnt[0]=cnt[1]=0;
        cnt1[0]=cnt1[1]=0;
        for(int j=l;j<=r;j++){
            cnt[j&1]++;
            cnt1[a[j].second&1]++;
        }
        if(cnt[0]!=cnt1[0]){
            puts("NO");
            return;
        }

        i=r+1;
    }
    puts("YES");


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