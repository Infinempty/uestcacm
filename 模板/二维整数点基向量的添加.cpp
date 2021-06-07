ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	//ax+by=gcd(a,b) 
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    ll r=exgcd(b,a%b,x,y);
    ll temp=y;
    y=x-(a/b)*y;
    x=temp;
    return r;
}
struct TwoD_BASE{
	int cnt;
	ll X1,X2,Y1,Y2;
	void init(){
		cnt=0;
		X1=X2=Y1=Y2=0;
	}
	void print_base(){
		printf("base 0:%lld %lld\n",X1,Y1);
		printf("base 1:%lld %lld\n",X2,Y2);
	}
	void add(ll x,ll y){
		ll gcdd=0,a=0,b=0;
		if(y==0&&x==0)return;
		if(cnt==0){
			X1=x;
			Y1=y;
			cnt++;
			if(Y1<0){
				X1=-X1;
				Y1=-Y1;
			}
		}else{
			gcdd=exgcd(Y1,y,a,b);
			if(gcdd==0){
				X1=gcd(X1,x);
				X2=gcd(X2,x);
				X1=(X1%X2+X2)%X2;
			}else{
				X2=gcd(X2,abs(y/gcdd*X1-Y1/gcdd*x));
				X1=a*X1+b*x;
				Y1=gcdd;
				X1=(X1%X2+X2)%X2;
			}
		}
	}
	bool judge(ll x,ll y){
		ll k;
		if(x==0&&y==0)return true;
		if(Y1==0){
			if(y!=0)return false;
			if(X1==0||x%X1!=0)return false;
			return true;
		}
		if(y%Y1!=0)return false;
		k=y/Y1;
		if(X2==0){
			if(x-k*X1!=0)return false;
		}
		else if((x-k*X1)%X2!=0)return false;
		return true;
	}
}dim; 
