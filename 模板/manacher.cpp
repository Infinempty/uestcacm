#include<bits/stdc++.h>
#define ll long long
#define maxn 51000100
using namespace std;
int n,hw[maxn];
char a[maxn],s[maxn<<1];
void manacher()
{
    int maxright=0,mid;
    for(int i=1;i<n;i++)
    {
        if(i<maxright)
            hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
        else
            hw[i]=1;
        for(;s[i+hw[i]]==s[i-hw[i]];++hw[i]);
        if(hw[i]+i>maxright)
        {
            maxright=hw[i]+i;
            mid=i;
        }
    }
}
void change()
{
    s[0]=s[1]='#';
    for(int i=0;i<n;i++)
    {
        s[i*2+2]=a[i];
        s[i*2+3]='#';
    }
    n=n*2+2;
    s[n]=0;
}
void solve(){
	scanf("%s",&a);
	n=strlen(a);
	change();
	manacher();
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=max(ans,hw[i]);
	} 
	printf("%d",ans-1);
}
signed main()
{
	int t=1;
	//scanf("%d",&t);
	while(t--){
		solve();
	}
}

