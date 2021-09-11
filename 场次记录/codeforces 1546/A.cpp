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

int a[MAXN],b[MAXN];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        sum1+=a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",b+i);
        sum2+=b[i];
    }
    if(sum1^sum2){
        puts("-1");
        return;
    }
    vector<pair<int,int> >ans;
    for(int i=1;i<=n;i++){
        if(a[i]==b[i])continue;
        int sta=a[i]<b[i];
        for(int j=i+1;j<=n&&a[i]^b[i];j++){
            if(sta^(a[j]<b[j])){
                int minn=min(abs(a[i]-b[i]),abs(a[j]-b[j]));
                if(sta){
                    a[i]+=minn;a[j]-=minn;
                    for(int k=1;k<=minn;k++){
                        ans.eb(mkp(j,i));
                    }
                }else{
                    a[i]-=minn;a[j]+=minn;
                    for(int k=1;k<=minn;k++){
                        ans.eb(mkp(i,j));
                    }
                }
            }
        }
    }
    printf("%d\n",ans.size());
    for(auto to:ans){
        printf("%d %d\n",to.first,to.second);
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