#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010,INF=1e9;
int n;
int ch[maxn][2];
int val[maxn],dat[maxn];
int Size[maxn],cnt[maxn];
int tot,root;
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
int New(int v) 
{
	val[++tot]=v;
	dat[tot]=rand();
	Size[tot]=1;
	cnt[tot]=1;
	return tot;
}
void pushup(int id) 
{
	Size[id]=Size[ch[id][0]]+Size[ch[id][1]]+cnt[id];
}
void build() 
{
	root=New(-INF),ch[root][1]=New(INF);
	pushup(root);
}
void Rotate(int &id,int d)//d==0左旋,d==1右旋
{
	int temp=ch[id][d^1];
	ch[id][d^1]=ch[temp][d];
	ch[temp][d]=id;
	id=temp;
	pushup(ch[id][d]),pushup(id);
}
void insert(int &id,int v)
{
	if(!id){
		id=New(v);
		return;
	}
	if(v==val[id]) cnt[id]++;
	else{
		int d=v<val[id] ? 0 : 1;
		insert(ch[id][d],v);
		if(dat[id]<dat[ch[id][d]]) Rotate(id,d^1);
	}
	pushup(id);
}
void Remove(int &id,int v) 
{
	if(!id) return;
	if(v==val[id]){
		if(cnt[id]>1){ 
			cnt[id]--,pushup(id); 
			return; 
		}
		if(ch[id][0] || ch[id][1]){
			if(!ch[id][1] || dat[ch[id][0]]>dat[ch[id][1]]) Rotate(id,1),Remove(ch[id][1],v);
			else Rotate(id,0),Remove(ch[id][0],v);
			pushup(id);
		}
		else id=0;
		return;
	}
	v<val[id] ? Remove(ch[id][0],v) : Remove(ch[id][1],v);
	pushup(id);
}
int get_rank(int id,int v)
{
	if(!id) return 0;
	if(v==val[id]) return Size[ch[id][0]]+1;
	else if(v<val[id]) return get_rank(ch[id][0],v);
	else return Size[ch[id][0]]+cnt[id]+get_rank(ch[id][1],v);
}
int get_val(int id,int rank) 
{
	if(!id) return INF;
	if(rank<=Size[ch[id][0]]) return get_val(ch[id][0],rank);
	else if(rank<=Size[ch[id][0]]+cnt[id]) return val[id];
	else return get_val(ch[id][1],rank-Size[ch[id][0]]-cnt[id]);
}
int get_pre(int v) 
{
	int id=root,pre;
	while(id){
		if(val[id]<v) pre=val[id],id=ch[id][1];
		else id=ch[id][0];
	}
	return pre;
}
int get_next(int v) 
{
	int id=root,next;
	while(id){
		if(val[id]>v) next=val[id],id=ch[id][0];
		else id=ch[id][1];
	}
	return next;
}
int main() 
{
	build();
	n=read();
	for(int i=1;i<=n;i++){
		int cmd=read(),x=read();
		if(cmd==1) insert(root,x);
		else if(cmd==2) Remove(root,x);
		else if(cmd==3) printf("%d\n",get_rank(root, x)-1);
		else if(cmd==4) printf("%d\n",get_val(root,x+1));
		else if(cmd==5) printf("%d\n",get_pre(x));
		else if(cmd==6) printf("%d\n",get_next(x));
	}
	return 0;
}
