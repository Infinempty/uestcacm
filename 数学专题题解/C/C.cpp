#include<iostream>
#include<vector>
#define ll long long
const ll MOD=1e9+7;
using namespace std;
vector<int> v1[100050],v2[100050];
ll ans=1,k;
void dfs1(int n,int fa){
    for(int i=0;i<v1[n].size();i++){
        if(v1[n][i]==fa)continue;
        v2[n].push_back(v1[n][i]);
        dfs1(v1[n][i],n);
    }
}
void dfs2(int n,int dep,int bro){
    int now_bro=0;
    if(dep<2){
        ans*=1ll*(k-bro-dep);
        ans%=MOD;
    }else{
        ans*=1ll*(k-bro-2);
        ans%=MOD;
    }
    for(int i=0;i<v2[n].size();i++){
        dfs2(v2[n][i],dep+1,now_bro);
        now_bro++;
    }

}
void solve(){
    int n,a,b;
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        v1[a].push_back(b);
        v1[b].push_back(a);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    printf("%lld",ans);
    return;
}

int main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}