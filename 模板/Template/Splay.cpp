#include<iostream>
#include<cstdio>
#define maxn 1000005
using namespace std;
int f[maxn],cnt[maxn],value[maxn],sons[maxn][2],sub_size[maxn],tot,root;                 
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
inline void S_Clear(int x)
{
    sons[x][0]=sons[x][1]=f[x]=sub_size[x]=cnt[x]=value[x]=0; 
    return;
}
inline bool get_which(int x)
{
    return sons[f[x]][1]==x;
}
inline void update(int x)
{
    if(x){  
        sub_size[x]=cnt[x];  
        if(sons[x][0]) sub_size[x]+=sub_size[sons[x][0]];  
        if(sons[x][1]) sub_size[x]+=sub_size[sons[x][1]];  
    }  
    return;
}
inline void rotate(int x)
{
    bool which_son=get_which(x);
    int father=f[x];
    int g_father=f[father];
    sons[father][which_son]=sons[x][which_son^1];
    f[sons[father][which_son]]=father;
    sons[x][which_son^1]=father;
    f[father]=x;
    f[x]=g_father;
    if(g_father) sons[g_father][sons[g_father][1]==father]=x;
    update(father);
    update(x);
    return;
}
inline void splay(int x)
{
    for(int fa;fa=f[x];rotate(x)) if(f[fa]) rotate((get_which(x)==get_which(fa)) ? fa : x);  
    root=x;
}
inline void insert(int x)
{
    if(!root){
        tot++;
        sons[tot][0]=sons[tot][1]=f[tot]=0;
        root=tot;
        sub_size[tot]=cnt[tot]++;
        value[tot]=x;
        return ;
    } 
    int now=root,fa=0;
    while(1){
        if(x==value[now]){
            cnt[now]++;
            update(now);
            update(fa);
            splay(now);
            break;
        }
        fa=now;
        now=sons[now][value[now]<x];
        if(!now){
            tot++;
            sons[tot][0]=sons[tot][1]=0;
            f[tot]=fa;
            sub_size[tot]=cnt[tot]=1;
            sons[fa][value[fa]<x]=tot;
            value[tot]=x;
            update(fa);
            splay(tot);
            break; 
        }
    }
}
inline int find_num(int x){ 
    int now=root;
    while(1){
        if(sons[now][0] && x<=sub_size[sons[now][0]]) now=sons[now][0];
        else{
            int temp=(sons[now][0] ? sub_size[sons[now][0]] : 0)+cnt[now];
            if(x<=temp) return value[now];
            x-=temp;
            now=sons[now][1];
        }
    }
}

inline int find_rank(int x)
{
     int now=root,ans=0;  
    while(1){  
        if(x<value[now]) now=sons[now][0];  
        else{  
            ans+=(sons[now][0] ? sub_size[sons[now][0]] : 0);  
            if(x==value[now]){ 
                splay(now); 
				return ans+1;  
            }  
            ans+=cnt[now];  
            now=sons[now][1];  
        }  
    }  
}
inline int find_pre()
{
    int now=sons[root][0];
    while(sons[now][1]) now=sons[now][1];
    return now;
}
inline int find_suffix()
{
    int now=sons[root][1];
    while(sons[now][0]) now=sons[now][0];
    return now;
}
inline void Remove(int x)
{
    int h=find_rank(x);
    if(cnt[root]>1){
		cnt[root]--; 
		update(root); 
		return;
    }  
    if(!sons[root][0] && !sons[root][1]) {
		S_Clear(root);
		root=0;
		return;
    }  
    if(!sons[root][0]){  
        int old_root=root; 
        root=sons[root][1];
        f[root]=0; 
        S_Clear(old_root); 
        return;  
    }  

    else if(!sons[root][1]){  
        int old_root=root; 
        root=sons[root][0]; 
        f[root]=0; 
        S_Clear(old_root); 
        return;  
    } 
    int left_max=find_pre(),old_root=root;  
    splay(left_max);  
    sons[root][1]=sons[old_root][1];  
    f[sons[old_root][1]]=root;  
    S_Clear(old_root);  
    update(root);  
}
int main()
{
    int n,op,v;
    n=read();
    for(int i=1;i<=n;i++){
		op=read();
		v=read();
		switch(op){
            case 1:
				insert(v);
				break;
            case 2:
				Remove(v);
				break;
            case 3:
				printf("%d\n",find_rank(v));
				break;
            case 4:
				printf("%d\n",find_num(v));
				break;
            case 5:
				insert(v);
				printf("%d\n",value[find_pre()]);
				Remove(v);
				break;
            case 6:
				insert(v);
				printf("%d\n",value[find_suffix()]);
				Remove(v);
				break;
        }
    }
    return 0;
}