#include <bits/stdc++.h>
#define ls(o) t[o].l
#define rs(o) t[o].r
#define pb push_back
using namespace std;
const double alpha=0.7;
const int maxn=100005;
int n,tot=0,rt=0;
struct Node
{
    bool del;
    int l,r,v,sz,valid;
    void New(int x)
    {
        l=r=0;
        v=x;
        sz=valid=1;
        del=0;
    }
}t[maxn<<2];
bool bad(int o)
{
    return ((double)t[ls(o)].sz>alpha*t[o].sz || (double)t[rs(o)].sz>alpha*t[o].sz);
}
void updata(int o)
{
    t[o].sz=t[ls(o)].sz+t[rs(o)].sz+!t[o].del;
    t[o].valid=t[ls(o)].valid+t[rs(o)].valid+!t[o].del;
}
void dfs(int o,vector<int> &v)
{
    if(!o) return ;
    dfs(ls(o),v);
    if(!t[o].del) v.pb(o);
    dfs(rs(o),v);
    return;
}
int build(vector<int> &v,int l,int r)
{
    if(l>=r) return 0;
    int mid=(l+r)>>1;
    int o=v[mid];
    ls(o)=build(v,l,mid);
    rs(o)=build(v,mid+1,r);
    updata(o);
    return o;
}
void rebuild(int &o)
{
    vector<int>v;
    dfs(o,v);
    o=build(v,0,(int)v.size());
}
void Insert(int x,int &o)
{
    if(!o){
        o=++tot;
        t[o].New(x);
        return ;
    }
    t[o].sz++;t[o].valid++;
    if(x>=t[o].v) Insert(x,rs(o));
    else Insert(x,ls(o));
    if(bad(o)) rebuild(o);
    return ;
}
int getrank(int o,int x)
{
    int ans=1;
    while(o){
        if(t[o].v>=x) o=ls(o);
        else{
            ans+=t[ls(o)].valid+!t[o].del;
            o=rs(o);
        }
    }
    return ans;
}
int findkth(int o,int x)
{
    while(o){
        if(!t[o].del&&t[ls(o)].valid+1==x) return t[o].v;
        if(t[ls(o)].valid>=x) o=ls(o);
        else{
            x-=t[ls(o)].valid+!t[o].del;
            o=rs(o);
        }
    }
}
void Delete(int o,int Rnk)
{
    if(!t[o].del&&Rnk==t[ls(o)].valid+1){
        t[o].del=1;
        --t[o].valid;
        return ;
    }
    --t[o].valid;
    if(Rnk<=t[ls(o)].valid+!t[o].del) Delete(ls(o),Rnk);
    else Delete(rs(o),Rnk-t[ls(o)].valid-!t[o].del);
}
int main()
{
    cin>>n;
    rt=0;
    while(n--){
        int opt,x;
        scanf("%d%d",&opt,&x);
        if(opt==1) Insert(x,rt);
        if(opt==2) Delete(rt,getrank(rt,x));
        if(opt==3) printf("%d\n",getrank(rt,x));
        if(opt==4) printf("%d\n",findkth(rt,x));
        if(opt==5) printf("%d\n",findkth(rt,getrank(rt,x)-1));
        if(opt==6) printf("%d\n",findkth(rt,getrank(rt,x+1)));
    }
    return 0;
}