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
const int MAXN=1050;
const int bk_sz=3420;
mt19937 rnd(114514);

char s[MAXN][MAXN],t[MAXN][MAXN],tmp[MAXN][MAXN];
void rot(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            tmp[j][n+1-i]=t[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[i][j]=tmp[i][j];
        }
    }
}
void move(int n){
    int xmin=INF,ymin=INF;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(t[i][j]=='#'){
                xmin=min(xmin,i);
                ymin=min(ymin,j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t[i][j]=t[i+xmin-1][j+ymin-1];
            if(t[i][j]!='#')t[i][j]='.';
        }
    }
}
bool check(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i][j]!=t[i][j])return false;
        }
    }
    return true;
}
void mainwork(int T){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++){
        scanf("%s",t[i]+1);
    }
    int xmin=INF,ymin=INF;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i][j]=='#'){
                xmin=min(xmin,i);
                ymin=min(ymin,j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            s[i][j]=s[i+xmin-1][j+ymin-1];
            if(s[i][j]!='#')s[i][j]='.';
        }
    }
    move(n);
    for(int i=1;i<=4;i++){
        if(check(n)){
            puts("Yes");
            return;
        }
        rot(n);
        move(n);
    }
    puts("No");

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