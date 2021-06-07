int exgcd(int a,int b,int &x,int &y)
{
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int r=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-(a/b)*y;
	return r;
}
int gcd(int a,int b)
{
	return b==0 ? a : gcd(b,a%b);
}