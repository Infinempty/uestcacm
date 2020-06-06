#include<bits/stdc++.h>
#define ll long long
#define INF 1e14
using namespace std;
const int maxn=100000+10;
struct TwoSAT
{
    int n;
    vector<int> G[maxn*2];
    bool mark[maxn*2];
    int S[maxn*2],c;


    bool dfs(int x)
    {
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        mark[x]=true;
        S[c++]=x;
        for(int i=0;i<G[x].size();i++)
            if(!dfs(G[x][i])) return false;
        return true;
    }
    
    void init(int n)
    {
        this->n=n;
        for(int i=0;i<2*n;i++) 
            G[i].clear();
        memset(mark,0,sizeof(mark));
    }

    void add_clause(int x,int xval,int y,int yval)
    {
        x=x*2+xval;
        y=y*2+yval;
        G[x].push_back(y);
        //G[y^1].push_back(x);
    }

    bool solve()
    {
        for(int i=0;i<2*n;i+=2)
        if(!mark[i] && !mark[i+1])
        {
            c=0;
            if(!dfs(i))
            {
                while(c>0) mark[S[--c]]=false;
                if(!dfs(i+1)) return false;
            }
        }
        return true;
    }
};
TwoSAT sat;
int inv(int a){
	if(a)return 0;
	else return 1;
}
void solve(){
    int n,m,a,b,c,u,v,w;
    scanf("%d %d",&n,&m);
    sat.init(n);
    for(int i=1;i<=m;i++){
    	scanf("%d %d %d %d %d %d",&a,&u,&b,&v,&c,&w);
    	sat.add_clause(a,inv(u),b,v);
    	sat.add_clause(a,inv(u),c,w);
    	sat.add_clause(b,inv(v),a,u);
    	sat.add_clause(b,inv(v),c,w);
    	sat.add_clause(c,inv(w),a,u);
    	sat.add_clause(c,inv(w),b,v);
	}
	if(sat.solve())printf("YES");
	else printf("NO");
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve(); 
    }
    
}
