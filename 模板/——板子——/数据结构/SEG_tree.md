```c++
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define pr pair<int,int>
#define ls(x) nd[2*(x)]
#define rs(x) nd[2*(x)+1]
#define N 100005
#define mod 1000000007
#define INF 2147483647
using namespace std;
int a[N];
struct node{
    int v,lazy;
}nd[4*N];
void push_up(int c){
    //…………
}
void push_down(int c){
    //ls(c).lazy rs(c).lazy;
    //ls(c).v rs(c).v
    //nd[c].lazy=0

}
void build(int c,int l,int r){
    if(l==r){
        nd[c].v=a[l];
        nd[c].lazy=0;
        return;
    }
    int mid=l+r>>1;
    build(2*c,l,mid);
    build(2*c+1,mid+1,r);
    push_up(c);
}
//单点修改
void modify(int pos,int v,int c,int l,int r){
    if(l==r){
        nd[c].v=v;
        return;
    }
    int mid=l+r>>1;
    if(pos<=mid)modify(pos,v,2*c,l,mid);
    else modify(pos,v,2*c+1,mid+1,r);
    push_up(c);
    return;
}
//区间修改
void modify_seg(int c,int l,int r,int L,int R,int v){
    if(L<=l&&R>=r){
        //nd[c].lazy
        //nd[c].v
        return;
    }
    if(nd[c].lazy)push_down(c);
    int mid=l+r>>1;
    if(L<=mid)modify_seg(2*c,l,mid,L,R,v);
    if(r>mid)modify_seg(2*c+1,mid+1,r,L,R,v);
    push_up(c);
    return;
}
int query(int c,int l,int r,int L,int R){
    if(L<=l&&R>=r)return nd[c].v;
    if(nd[c].lazy)push_down(c);
    int mid=l+r>>1,a=-1,b=-1;
    if(l<=mid)a=query(2*c,l,mid,L,R);
    if(r>mid)b=query(2*c+1,mid+1,r,L,R);
    //return max(a,b);
    //return …………;
}
int main() {
	IOS;
	return 0;
}
```

