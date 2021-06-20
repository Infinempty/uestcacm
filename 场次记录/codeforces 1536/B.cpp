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
map<string,int> mp;
int t[10];
void mainwork(int T){
    int n;
    scanf("%d",&n);
    cin>> s;
    string tmp;
    mp.clear();
    for(int i=0;i<n;i++){
        for(int j=1;i+j-1<=n;j++){
            tmp=s.substr(i,j);
            if(!mp.count(tmp)){
                mp.insert(mkp(tmp,1));
            }
            //cout<<tmp<<'\n';
        }
    }
    for(int i=1;i<=499950;i++){
        int now=i;
        tmp.clear();
        bool ok=1;
        while(now){
            if(now%27==0){
                ok=0;
                break;
            }
            tmp.push_back(now%27+'a'-1);
            now/=27;
        }
        if(!ok)continue;
        reverse(all(tmp));
        if(!mp.count(tmp)){
            cout<<tmp<<'\n';
            return;
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