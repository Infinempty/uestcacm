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
int cnt[30];

char work(int in){
    return in+'a';
}
void mainwork(int T){
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=0;i<30;i++)cnt[i]=0;
    for(int i=1;i<=n;i++){
        cnt[s[i]-'a']++;
    }
    int ok=-1;
    for(int i=0;i<26;i++){
        if(cnt[i]==1){
            ok=i;
            break;
        }
    }
    if(~ok){
        cnt[ok]--;
        printf("%c",work(ok));
        for(int i=0;i<26;i++){
            for(int j=1;j<=cnt[i];j++){
                printf("%c",work(i));
            }
        }
        puts("");
        return;
    }
    int minn[3]={-1,-1,-1};
    for(int i=0;i<26;i++){
        if(cnt[i]){
            if(~minn[0]){
                if(~minn[1]){
                    minn[2]=i;
                    break;
                }else minn[1]=i;
            }else minn[0]=i;
        }
    }
    if(2*cnt[minn[0]]-2>n){
        if(minn[1]==-1){
            puts(s+1);
            return;
        }else if(minn[2]==-1){
            printf("%c",minn[0]+'a');
            for(int i=1;i<=cnt[minn[1]];i++){
                printf("%c",minn[1]+'a');
            }
            for(int i=1;i<cnt[minn[0]];i++){
                printf("%c",minn[0]+'a');
            }
            puts("");
        }else{
            printf("%c",minn[0]+'a');
            printf("%c",minn[1]+'a');
            for(int i=1;i<cnt[minn[0]];i++){
                printf("%c",minn[0]+'a');
            }
            printf("%c",minn[2]+'a');
            for(int i=1;i<cnt[minn[1]];i++){
                printf("%c",minn[1]+'a');
            }
            for(int i=1;i<cnt[minn[2]];i++){
                printf("%c",minn[2]+'a');
            }
            for(int i=minn[2]+1;i<26;i++){
                for(int j=1;j<=cnt[i];j++){
                    printf("%c",i+'a');
                }
            }
            puts("");
        }
        return;
    }
    printf("%c",work(minn[0]));
    cnt[minn[0]]--;
    for(int i=minn[0]+1;cnt[minn[0]]&&i<26;i++){
        int sum=min(cnt[minn[0]],cnt[i]);
        cnt[minn[0]]-=sum;
        cnt[i]-=sum;
        for(int j=1;j<=sum;j++){
            printf("%c%c",work(minn[0]),work(i));
        }
    }
    if(cnt[minn[0]]){
        printf("%c",work(minn[0]));
    }
    for(int i=minn[0]+1;i<26;i++){
        for(int j=1;j<=cnt[i];j++){
            printf("%c",work(i));
        }
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