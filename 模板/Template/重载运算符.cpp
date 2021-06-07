struct node
{
	ll l,r;
	bool operator <(const node &a)const{
		if(l==a.l) return r<a.r;
		return l<a.l;
	}
};