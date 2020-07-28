#include<iostream>
#include<string.h>
#include<bitset>
#define MOD 1000000007
#define ll long long
using namespace std;
bitset<1005>a[12],ans;
char s[5000005];
//算法主要用于柔性的字符串匹配 
void ShiftAnd(){
	//需要注意这里应当给字符集编号 本题因字符集仅有0-9因而没有编号 
	int n,m,tmp,len;
	//n是每个位上的限制条件
	//m是每个位上的限制个数 
	while(cin>>n){
		for(int i=0;i<10;i++)a[i].reset();
		for(int i=1;i<=n;i++){
			scanf("%d",&m);
			for(int j=1;j<=m;j++){
				scanf("%d",&tmp);
				a[tmp].set(i-1);
			}	
		}
		//for(int i=0;i<10;i++)cout<<a[i]<<endl;
		scanf("%s",s);
		len=strlen(s);
		for(int i=0;i<len;i++){
			ans<<=1;
			ans.set(0);
			//cout<<ans<<endl;
			ans&=a[s[i]-'0'];
			if(ans[n-1]){
				char ch=s[i+1];
                s[i+1]='\0';
                puts(s+i-n+1);
                s[i+1]=ch;
			}
		}
	}	
}
void solve(int T){
	ShiftAnd(); 
}
signed main()
{
	int t=1;
	//scanf("%d",&t);
	for(int i=1;i<=t;i++){
		solve(i);
	}
}







