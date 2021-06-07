for(int i=1;i<=n;i++) scanf("%d",&a0[i]);
//sort(a0+1,a0+1+n);
unique_copy(a0+1,a0+1+n,a+1);
n=0;
for(int i=1;a[i]!=0;i++){
	//printf("%d ",a[i]);
	n++;
}