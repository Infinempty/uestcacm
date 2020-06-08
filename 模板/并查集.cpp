#include<iostream>
using namespace std;
int data[10010];
int n,m,t,x,y;
/*
https://www.luogu.com.cn/problemnew/solution/P3367
*/
int find(int x)
{
	if(data[x]==x)return x;
	data[x]=find(data[x]);
	return data[x];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)data[i]=i;
	for(int i=1;i<=m;i++){
		cin>>t>>x>>y;
		if(t==1){
			data[find(x)]=find(y);
		}
		else if(t==2){
			if(find(x)==find(y))cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}
}
