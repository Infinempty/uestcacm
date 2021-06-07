while(l<=r){
		int mid=(l+r)>>1;
		if(judge(mid)) l=mid+1;
		else r=mid-1;
}
cout<<r<<endl;

//下面是使多个数中的最小值最大化的二分:
int l=0,r=n;
while(r-l>1){
	int m=(r+l)/2;
    if(check(m)) l=m;
    else r=m;
}
cout<<l-1<<"\n";