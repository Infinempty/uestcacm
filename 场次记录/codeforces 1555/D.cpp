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

char s[MAXN];

int sum[MAXN][3][3];
void mainwork(int T){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                sum[i][j][k]=sum[i-1][j][k];
            }
        }
        sum[i][i%3][s[i]-'a']++;
    }
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        int per[3]={0,1,2};
        int ans=INF,tmp;
        do{
            tmp=r-l+1;
            for(int i=0;i<3;i++){
                tmp-=sum[r][per[i]][i]-sum[l-1][per[i]][i];
            }
            ans=min(ans,tmp);
        }while(next_permutation(per,per+3));
        printf("%d\n",ans);
    }   
}
signed main(){
    //IOS;
#ifndef ONLINE_JUDGE
    freopen("Ranulx.in","r",stdin);
    freopen("Ranulx.out","w",stdout);
#endif
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        mainwork(i);
    }
}