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

queue<int> q[MAXN];
priority_queue<pair<int,int> >mes;
int cnt[MAXN],ccnt[MAXN];
vector<int> lsh;
int getid(int x){
    return lower_bound(all(lsh),x)-lsh.begin()+1;
}
pair<int,int> stu[MAXN];

priority_queue<pair<double,int> > pq[MAXN];

void mainwork(int T){
    int n;
    scanf("%d",&n);
    long double ans=0;
    for(int i=1;i<=n;i++){
        int id,ct;
        scanf("%d%d",&stu[i].first,&stu[i].second);
        lsh.push_back(stu[i].first);
    }
    sort(all(lsh));
    lsh.erase(unique(all(lsh)),lsh.end());
    for(int i=1;i<=n;i++){
        q[getid(stu[i].first)].push(stu[i].second);
        cnt[getid(stu[i].first)]++;
    }
    int m=lsh.size();
    for(int i=1;i<=m;i++){
        mes.push(mkp(cnt[i],i));
    }
    vector<int> fin;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=20;j++)ccnt[j]=0;
        while(!q[i].empty()){
            int now=q[i].front();q[i].pop();
            ccnt[now]++;
        }
        for(int j=1;j<=20;j++){
            double tmp=0;
            for(int k=1;k<=20;k++){
                if(k>=j)tmp+=ccnt[k];
                else tmp+=1.0*ccnt[k]*k/j;
            }
            pq[j].push(mkp(tmp,i));
        }
    }
    for(int i=1;i<=20;i++){
        vector<int>tmp;
        long double now=0;
        for(int j=1;j<=i&&!pq[i].empty();j++){
            now+=pq[i].top().first;
            tmp.push_back(pq[i].top().second);
            pq[i].pop();
        }
        if(now>ans){
            ans=now;
            fin=tmp;
        }
    }
    printf("%d\n",fin.size());
    for(auto i:fin){
        printf("%d ",lsh[i-1]);
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