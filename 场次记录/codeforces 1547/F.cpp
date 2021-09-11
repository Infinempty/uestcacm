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
const int MAXN=400050;
const int bk_sz=3420;
mt19937 rnd(114514);

int lg[MAXN];
ll gcdd[MAXN][20];
ll a[MAXN];

void create_ST(int n){
    lg[0]=-1;
	for(int i=1;i<=n;i++){
		lg[i]=lg[i/2]+1;
        gcdd[i][0]=a[i];
	}
	for(int i=1;i<=lg[n];i++)
    {
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            gcdd[j][i]=__gcd(gcdd[j][i-1],gcdd[j+(1<<(i-1))][i-1]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;i+(1<<j)-1<=n;j++){
    //         printf("%d ",gcdd[i][j]);
    //     }
    //     puts("");
    // }
}
ll query(int l,int r){
	int len=lg[r-l+1];
    return __gcd(gcdd[l][len],gcdd[r-(1<<(len))+1][len]);
}
bool check(int len,int n){
    ll now=query(1,1+len);
    for(int i=2;i<=n;i++){
        if(query(i,i+len)!=now){
            return false;
        }
    }
    return true;
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        a[i+n]=a[i];
    }
    create_ST(n<<1);
    int l=0,r=n-1;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid,n)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%d\n",l);
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