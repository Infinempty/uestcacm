bool vis[maxn+20];
int tot,pri[maxn+20],e[maxn+20],d[maxn+20];
void sieve()
{
	d[1]=inv[1]=1;
	for(int i=2;i<=maxn-1;i++){
		if(!vis[i]){
            pri[++tot]=i;
            e[i]=1;
            d[i]=2;
        }
		for(int j=1;i*pri[j]<=maxn-1;j++){
			vis[i*pri[j]]=1;
			if(!(i%pri[j])){
				d[i*pri[j]]=d[i]/(e[i]+1)*(e[i]+2);
				e[i*pri[j]]=e[i]+1;
				break;
			}
			else{
				d[i*pri[j]]=d[i]<<1;
				e[i*pri[j]]=1;
			}
		}
	}
	return;
}