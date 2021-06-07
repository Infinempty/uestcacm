namespace Min25{
	const int maxn=200050;
	typedef long long type;
	struct Min_25{
		type mod,inv;
		type vis[maxn];
		type pri[maxn],w[maxn],id1[maxn],id2[maxn],g[maxn],tr_value[maxn];
		type n,tot,m;
		type Sqr;
		//只需要输入n 
		type mpow(type a,type n,type MOD){
			if(a==1||n==0)return 1;
			type ans=1;
			a%=MOD;
			while(n!=0){
				if(n&1)ans=(ans*a)%MOD;
				n>>=1;
				a=(a*a)%MOD;
			}
			return ans%MOD;
		}
		type f(type x){
			return x;
			//return 1;
		}
		type prefix(type x){
			type res=0;
			x%=mod;
			res=(((x+1)%mod)*x)%mod;
			res=(res*inv)%mod;
			res--;
			res=(res+mod)%mod;
			return res;
			//return x-1;
			//把所有值当成质数算出的前缀和 
		}
		void Init(type n,type mod,type inv){
			this->n=n;
			this->mod=mod;
			this->inv=inv;
			m=0,tot=0;
			Sqr=sqrt(n+0.5);
			for(type i=0;i<=2*Sqr+10;i++){
				vis[i]=pri[i]=w[i]=id1[i]=id2[i]=g[i]=0;
			}
		}
		void Euler_sieve(){
			vis[1]=1;
			for(type i=2;i<=Sqr;i++){
				if(!vis[i]){
					pri[++tot]=i;
					tr_value[tot]=f(i)+tr_value[tot-1];
					tr_value[tot]%=mod;
				}
				for(type j=1;j<=tot&&i*pri[j]<=Sqr;j++){
					vis[i*pri[j]]=1;
					if(i%pri[j]==0)break;
				}
			}
			
		}
		void First_step(){
			for (type i=1,j;i<=n;i=j+1){
				j=n/(n/i);
				w[++m]=n/i;
				if (w[m]<=Sqr) id1[w[m]]=m;
				else id2[n/w[m]]=m;
				//数论分块不用管 
				g[m]=(prefix(w[m]))%mod;
				//把m当成质数计算2-n的和 
			}
			for (type j=1;j<=tot;++j)
				for (type i=1;i<=m&&pri[j]*pri[j]<=w[i];++i){
					type k=(w[i]/pri[j]<=Sqr)?id1[w[i]/pri[j]]:id2[n/(w[i]/pri[j])];
					//id1是小于sqr的数的更新下标,id2则是大于 
					g[i]=g[i]-((g[k]-tr_value[j-1]+mod)%mod*f(pri[j]))%mod;//
					g[i]=(g[i]+mod)%mod;
				}
		}
		/*void Second_step(){
			
		}*/
	};
}
Min25::Min_25 sieve;