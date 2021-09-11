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

int a[MAXN];
int lg[MAXN]={-1};
int maxn[MAXN][20];
int minn[MAXN][20];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void create_ST(int n){
	for(int i=1;i<=n;i++){
		lg[i]=lg[i/2]+1;
		maxn[i][0]=a[i];
		minn[i][0]=a[i];
	}
	for(int i=1;i<=lg[n];i++)
    {
        for(int j=1;j+(1<<i)-1<=n;j++)
        {
            maxn[j][i]=max(maxn[j][i-1],maxn[j+(1<<(i-1))][i-1]);
            minn[j][i]=min(minn[j][i-1],minn[j+(1<<(i-1))][i-1]);
        }
    }
}
int query_max(int l,int r){
	int len=lg[r-l+1];
    return max(maxn[l][len],maxn[r-(1<<(len))+1][len]);
}
int query_min(int l,int r){
	int len=lg[r-l+1];
    return min(minn[l][len],minn[r-(1<<(len))+1][len]);
}

void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    create_ST(n);
    ll ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i-1;
        while(i!=1&&l<r){
            int mid=(l+r)>>1;
            if(query_min(mid,i)<a[i]){
                l=mid+1;
            }else r=mid;
        }
        int lb=i,rb=n;
        while(i!=n&&lb<rb){
            int mid=(lb+rb+1)>>1;
            if(query_min(i,mid)<a[i]){
                rb=mid-1;
            }else lb=mid;
        }
        printf("%d %d %d\n",i,l,rb);
        
        ans=max(ans,1ll*query_min(l,rb)*query_max(l,rb));
    }
    printf("%lld\n",ans);
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