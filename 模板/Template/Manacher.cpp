#pragma GCC optimize (3)
#include<bits/stdc++.h>
#define PII pair<int,int>
#define ll long long
#define N 20000001
using namespace std;
int p[N*2],l,maxp,p0,ans;
char ss[N*4],a[N*2];
void manacher()
{
	for(int i=1;i<l;i+=1){
		if(i<maxp) p[i]=min(p[2*p0-i],p[p0]+p0-i);
		else p[i]=1;
		while(ss[i-p[i]]==ss[i+p[i]]) p[i]++;
		if(i+p[i]>maxp) maxp=i+p[i];
		p0=i;
	}
}
int main()
{
	int n,place=0;
	cin>>n;
	scanf("%s",a+1);
	l=strlen(a+1);
	for(int i=1;i<=l;i++){
		ss[i*2]=a[i];
		ss[i*2+1]='#';
	}
	l=l*2+2;
	ss[0]='^';
	ss[1]='#';
	ss[l]='0';
	manacher();
	for(int i=1;i<=l;i++){
		if(p[i]-1>ans){
			ans=p[i]-1;
			place=i;
		}
	}
	cout<<ans<<endl;
	for(int i=place-ans+1;i<=place+ans-1;i++) if(ss[i]!='#' && ss[i]!='0') printf("%c",ss[i]);
	return 0;
}
