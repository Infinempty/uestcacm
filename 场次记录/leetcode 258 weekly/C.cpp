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

class Solution {
public:
    string s;
    int ans;
    int n;
    string a,b;
    bool check(){
        int n1=a.size(),n2=b.size();
        //if(n1^n2)return false;
        for(int i=0;i<n1;i++){
            if(a[i]!=a[n1-1-i])return false;
        }
        for(int i=0;i<n2;i++){
            if(b[i]!=b[n2-1-i])return false;
        }
        return true;
    }
    void dfs(int dep){
        if(dep==n){
            if(check()){
                int n1=a.size(),n2=b.size();
                ans=max(ans,n1*n2);
            }
            return ;
        }
        dfs(dep+1);
        a.push_back(s[dep]);
        dfs(dep+1);
        a.pop_back();
        b.push_back(s[dep]);
        dfs(dep+1);
        b.pop_back();
    }
    int maxProduct(string ss) {
        ans=0;
        s=ss;
        n=ss.size();
        dfs(0);
        return ans;
    }
};

void mainwork(int T){

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