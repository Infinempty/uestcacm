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
bool check(int goal1,int goal2,int rem1,int rem2){
    int rem[2]={rem1,rem2},goal[2]={goal1,goal2};
    int maxx=goal[1]>goal[0];
    int minn=maxx?0:1;
    return (goal[maxx]-goal[minn])>rem[minn];
}
int dfs(int rem1,int rem2,int goal1,int goal2){
    int now=11-rem1-rem2;
    if(now==11)return 10;
    if(check(goal1,goal2,rem1,rem2))return now-1;
    if(s[now]=='1'){
        if(now&1)return dfs(rem1-1,rem2,goal1+1,goal2);
        else return dfs(rem1,rem2-1,goal1,goal2+1);
    }else if(s[now]=='0'){
        if(now&1)return dfs(rem1-1,rem2,goal1,goal2);
        else return dfs(rem1,rem2-1,goal1,goal2);
    }else{
        int ans=INF;
        if(now&1){
            ans=min(ans,dfs(rem1-1,rem2,goal1+1,goal2));
            ans=min(ans,dfs(rem1-1,rem2,goal1,goal2));
        }else{
            ans=min(ans,dfs(rem1,rem2-1,goal1,goal2+1));
            ans=min(ans,dfs(rem1,rem2-1,goal1,goal2));
        }
        return ans;
    }
}
void mainwork(int T){
    scanf("%s",s+1);
    printf("%d\n",dfs(5,5,0,0));
    
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