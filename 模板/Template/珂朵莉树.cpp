//查询区间内有多少个数不等于c，然后将区间所有数都修改为c
#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define ull unsigned long long
#define INFI 2147483647
#define INFL 9223372036854775807
#define INFU 18446744073709551615
#define maxn 100010
using namespace std;
//using namespace __gnu_pbds;
const double PI=acos(-1.0);
const double eps=1e-6;
int n,m,a[maxn];
struct Node
{
    int l,r,v;
    Node(int a,int b=0,int c=0);
    bool operator < (const Node &a)const{
		if(l==a.l) return r<a.r;
		return l<a.l;
	}
};
Node::Node(int a,int b,int c)
{
    l=a;
    r=b;
    v=c;
}
set<Node> Tree;
set<Node>::iterator split(int x)
{
    set<Node>::iterator it=Tree.lower_bound(Node(x));
    if(it!=Tree.end() && it->l==x)
    return it;
    it--;
    int l=it->l,r=it->r;
    int v=it->v;
    Tree.erase(it);
    Tree.insert(Node(l,x-1,v));
    return Tree.insert(Node(x,r,v)).first;
}
int i_update(int l,int r,int v)
{
    int ans=0;
    set<Node>::iterator it1=split(l),it2=split(r+1);
    for(set<Node>::iterator it=it1;it!=it2;it++) if(it->v!=v) ans+=(it->r-it->l+1);
    Tree.erase(it1,it2);
    Tree.insert(Node(l,r,v));
    return ans;
}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    n=read();
    for(int i=1;i<=n;++i) a[i]=read();
    if(a[n]>=0) a[n+1]=a[n]-1;
    else a[n+1]=a[n]+1;
    for(int i=1;i<=n;){
        int j=i; while(a[j]==a[i]) j++;
        Node x(i,j-1,a[i]);
        Tree.insert(x);
        i=j;
    }
    m=read();
    for(int i=1;i<=m;++i){
        int l=read(),r=read(),c=read();
        printf("%d\n",i_update(l,r,c));
    }
	return 0;
}