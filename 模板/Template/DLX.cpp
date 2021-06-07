//n行m列的01矩阵,挑选出若干行,使得对于矩阵的每一列j,在你挑选的这些行中,有且仅有一行的第j个元素为1
#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define ll long long
#define rgi register int
#define rgl register ll
#define il inline
const int N=510;
int n,m,idx,ans;
int first[N],siz[N],stk[N];
struct DLXNODE 
{
	int lc,rc,up,dn,r,c;
};
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
struct DLX 
{
	static const int MAXSIZE=1e5+10;
#define IT(i,A,x) for(i=A[x];i!=x;i=A[i])
	int n,m,tot,first[MAXSIZE+10],siz[MAXSIZE+10];
	int L[MAXSIZE+10],R[MAXSIZE+10],U[MAXSIZE+10],D[MAXSIZE+10];
	int col[MAXSIZE+10],row[MAXSIZE+10];
	void build(const int &r,const int &c) 
	{
		n=r,m=c;
		for(rgi i=0;i<=c;++i){
			L[i]=i-1,R[i]=i+1;
			U[i]=D[i]=i;
		}
		L[0]=c,R[c]=0,tot=c;
		memset(first,0,sizeof(first));
		memset(siz,0,sizeof(siz));
	}
	void insert(const int &r,const int &c) 
	{
		col[++tot]=c,row[tot]=r,++siz[c];
		D[tot]=D[c],U[D[c]]=tot,U[tot]=c,D[c]=tot;
		if(!first[r]) first[r]=L[tot]=R[tot]=tot;
		else {
			R[tot]=R[first[r]],L[R[first[r]]]=tot;
			L[tot]=first[r],R[first[r]]=tot;
		}
	}
	void remove(const int &c) 
	{
		rgi i,j;
		L[R[c]]=L[c],R[L[c]]=R[c];
		IT(i,D,c) 
		IT(j,R,i)
		U[D[j]]=U[j],D[U[j]]=D[j],--siz[col[j]];
	}
	void recover(const int &c) 
	{
		rgi i,j;
		IT(i,U,c) 
		IT(j,L,i)
		U[D[j]]=D[U[j]]=j,++siz[col[j]];
		L[R[c]]=R[L[c]]=c;
	}
	bool dance(int dep) 
	{
		if(!R[0]){ 
			ans=dep; 
			return 1; 
		}
		rgi i,j,c=R[0];
		IT(i,R,0) if(siz[i]<siz[c]) c=i;		
		remove(c);
		IT(i,D,c){
			stk[dep]=row[i];
			IT(j,R,i) remove(col[j]);
			if(dance(dep+1)) return 1;
			IT(j,L,i) recover(col[j]);
		}
		recover(c);		
		return 0;
	}
#undef IT
}solver;
int main() 
{
	n=read(),m=read();
	solver.build(n, m);
	for(rgi i=1;i<=n;++i){
		for(rgi j=1;j<=m;++j){
			int x=read();
			if(x) solver.insert(i, j);
	} 
	solver.dance(1);
	if(ans) for(rgi i=1;i<ans;++i) printf("%d ",stk[i]);
	else puts("No Solution!");
	return 0;
}