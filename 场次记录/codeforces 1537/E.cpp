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

string s;
void mainwork(int T){
    int n,k;
    cin>>n>>k;
    cin>>s;
    string tmp,ans;
    ans.pb(s[0]);
    queue<char> q;
    for(int i=1;i<s.size();i++){
        if(s[i]>ans[0])break;
        else if(s[i]==ans[0])q.push(s[i]);
        else {
            while(!q.empty()){
                ans.pb(q.front());
                q.pop();
            }
            ans.pb(s[i]);
        }
    }
    for(int i=1;i<=k/ans.size();i++){
        cout<<ans;
    }
    for(int i=0;i<k%ans.size();i++){
        cout<<ans[i];
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