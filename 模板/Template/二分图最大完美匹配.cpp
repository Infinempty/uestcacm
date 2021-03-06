const int N=500;
int n,m,e[N+7][N+7];
int mb[N+7],vb[N+7],ka[N+7],kb[N+7],p[N+7],c[N+7];
int qf,qb,q[N+7];
void Bfs(int u)
{
    int a,v=0,vl=0,d;
    for(int i=1;i<=n;i++) p[i]=0,c[i]=inf;
    mb[v]=u;
    do{
        a=mb[v],d=inf,vb[v]=1;
        for(int b=1;b<=n;b++)if(!vb[b]){
            if(c[b]>ka[a]+kb[b]-e[a][b]) c[b]=ka[a]+kb[b]-e[a][b],p[b]=v;
            if(c[b]<d) d=c[b],vl=b;
        }
        for(int b=0;b<=n;b++){
            if(vb[b]) ka[mb[b]]-=d,kb[b]+=d;
            else c[b]-=d;
        }
        v=vl;
    }while(mb[v]);
    while(v) mb[v]=mb[p[v]],v=p[v];
}
ll KM()
{
    for(int i=1;i<=n;i++) mb[i]=ka[i]=kb[i]=0;
    for(int a=1;a<=n;a++){
    	for(int b=1;b<=n;b++) vb[b]=0;
		Bfs(a);
	}
	ll res=0;
	for(int b=1;b<=n;b++) res+=e[mb[b]][b];
	return res;
}
int main()
{
	n=ri,m=ri;
	for(int a=1;a<=n;a++) for(int b=1;b<=n;b++) e[a][b]=-inf;
	for(int i=1;i<=m;i++){
		int u=ri,v=ri,w=ri;
		e[u][v]=max(e[u][v],w);
	}
	printf("%lld\n",KM());
	for(int u=1;u<=n;u++) printf("%d ",mb[u]);puts("");
	return 0;
}