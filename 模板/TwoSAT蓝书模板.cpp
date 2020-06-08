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
    	//����x����㣬xval����ȡֵ��yͬ�� y^1����y+1
		//���߲���һ�ɲ��� ���ݳ���������߲��Ǻ���˼�� 
        x=x*2+xval;
        y=y*2+yval;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
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
