```c++
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0)
#define ll long long
#define pr pair<int,int>
#define N 100005
#define mod 1000000007
#define INF 2147483647

#define lc(x) nd[(x)].ch[0]
#define rc(x) nd[(x)].ch[1]
#define fa(x) nd[(x)].ch[2]
using namespace std;

struct SplayTree
{
    int ch[3],siz,cnt,v;
    SplayTree(){}
    SplayTree(int _f,int _v):siz(1),v(_v),cnt(1){
        ch[0]=ch[1]=0,ch[2]=_f;
    }
}nd[N];
int rt,siz,x;
void update(int x){}
void push_up(int x){
    // ……
    nd[x].siz=nd[lc(x)].siz+nd[rc(x)].siz+nd[x].cnt;
    return;
}

void push_down(int x){
    //……
    if(lc(x))update(lc(x));
    if(rc(x))update(rc(x));
    return;
}

void rotate(int x,int &k){
    int y=fa(x),z=fa(y),l=rc(y)==x,r=l^1;
    if(y==k)k=x;
    else nd[z].ch[rc(z)==y]=x;
    fa(x)=z,fa(y)=x,fa(nd[x].ch[r])=y;
    nd[y].ch[l]=nd[x].ch[r];
    nd[x].ch[r]=y;
    push_up(y);
    push_up(x);
    return;
}
//x转到k的位置
void splay(int x,int &k){
    int y,z;
    while(x!=k){
        y=fa(x);z=fa(y);
        if(y!=k){
            if(lc(z)==y^lc(y)==x)rotate(x,k);
            else rotate(y,k);
        }
        rotate(x,k);
    }
    return;
}
void add(int &x,int key,int fa){
    if(!x){
        nd[x=++siz]=SplayTree(fa,key);
        splay(x,rt);
        return;
    }
    if(nd[x].v==key)nd[x].siz++,nd[x].cnt++,splay(x,rt);
    else if(key<nd[x].v)add(lc(x),key,x);
    else add(rc(x),key,x);
    return;
}
//线段树建树返回rt
int v[N];
int build(int l, int r) {
    if (l > r)return 0;
    int mid = l + r >> 1, x;
    nd[x = ++siz] = SplayTree(0, v[mid]);
    lc(x) = build(l, mid-1); if (lc(x))fa(lc(x)) = x;
    rc(x) = build(mid + 1, r); if (rc(x))fa(rc(x)) = x;
    push_up(x);
    return x;
}

int pre(int x,int key){
    int k=-1;
    while(x){
        if(key>nd[x].v)k=x;
        x=nd[x].ch[key>nd[x].v];
    }
    return k;
}
int nxt(int x,int key){
    int k=-1;
    while(x){
        if(key<nd[x].v)k=x;
        x=nd[x].ch[key>=nd[x].v];
    }
    return k;
}
void del(int x,int key){
    if(!x)return;
    if(nd[x].v==key){
        if(nd[x].cnt>1)nd[x].cnt--,nd[x].siz--,splay(x,rt);
        else{
            int x1=pre(rt,key),x2=nxt(rt,key);
            if(~x1&&~x2){
                splay(x1,rt);
                splay(x2,rc(x1));
                lc(x2)=0;
                push_up(x2);
                splay(x2,rt);
            }
            else if(!~x1&&!~x2)rt=0;
            else if(!~x1){
                splay(x2,rt);
                lc(x2)=0;
                push_up(x2);
            }
            else{
                splay(x1,rt);
                rc(x1)=0;
                push_up(x1);
            }
        }
    }
    else if(key<nd[x].v)del(lc(x),key);
    else del(rc(x),key);
    return;
}
int getrank(int x,int key){
    if(!x)return 0;
    if(key<nd[x].v)return getrank(lc(x),key);
    else if(key>nd[x].v)return getrank(rc(x),key)+nd[lc(x)].siz+nd[x].cnt;
    else return nd[lc(x)].siz+1;
}
//rank为k的数
int select(int x,int k){
    if(!x)return 0;
    if(nd[lc(x)].siz>=k)return select(lc(x),k);
    else if(nd[lc(x)].siz<k&&nd[lc(x)].siz+nd[x].cnt>=k) return nd[x].v;
    else return select(rc(x),k-nd[lc(x)].siz-nd[x].cnt);
}

int main() {
	IOS;
    int n,op,x;
    cin>>n;
    while(n--){
        cin>>op>>x;
        if(op==1)add(rt,x,0);
        else if(op==2)del(rt,x);
        else if(op==3)cout<<getrank(rt,x)<<'\n';
        else if(op==4)cout<<select(rt,x)<<'\n';
        else if(op==5)cout<<nd[pre(rt,x)].v<<'\n';
        else cout<<nd[nxt(rt,x)].v<<'\n';
    }
	return 0;
}
```

