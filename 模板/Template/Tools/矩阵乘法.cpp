struct Mat
{
	long long a[5][5];
	Mat operator *(const Mat z)
	{
		Mat f;
		memset(f.a,0,sizeof(f.a));
		for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) for(int k=1;k<=3;k++) f.a[i][j]=(f.a[i][j]+a[k][j]*z.a[i][k]%(mod-1))%(mod-1);
		return f;
	}
}e