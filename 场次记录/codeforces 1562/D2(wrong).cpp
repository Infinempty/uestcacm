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

char s[MAXN];
int sum[MAXN];
void mainwork(int T){
    int n,q;
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    int sta=1;
    for(int i=1;i<=n;i++){
        int now=s[i]=='+'?1:-1;
        now*=sta;
        sum[i]=sum[i-1]+now;
        sta*=-1;
        //printf("%d ",sum[i]);
    }
    //puts("");

    for(int i=1;i<=q;i++){
        int l,r,ans=0;
        scanf("%d%d",&l,&r);
        int lb=l,rb=r;
        int tmp=abs(sum[r]-sum[l-1]);
        if(!tmp){
            puts("0");
            continue;
        }
        int val;
        if(tmp&1)val=sum[r]-sum[l-1];
        else val=sum[r-1]-sum[l-1],rb--;
        val=(val+1)/2;
        while(lb+1<rb){
            int mid=(lb+rb)>>1;
            int tt=sum[mid]-sum[l-1];
            if(tt<val){
                if(sum[lb]-sum[l-1]<val)lb=mid;
                else rb=mid;
            }else{
                if(sum[lb]-sum[l-1]<val)rb=mid;
                else lb=mid;
            }
        }
        int idx;
        if(sum[lb]-sum[l-1]==val){
            if((sum[r]-sum[l-1])*(sum[lb]-sum[lb+1])>0){
                idx=lb+1;
            }else idx=lb;
        }
        else {
            if((sum[r]-sum[l-1])*(sum[rb]-sum[rb+1])>0){
                idx=rb+1;
            }else idx=rb;
        }
        if(idx>r-1)idx=r-1;
        if(tmp&1){
            printf("1\n%d\n",idx);
        }else {
            printf("2\n%d %d\n",idx,r);
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