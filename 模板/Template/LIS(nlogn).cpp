#include<bits/stdc++.h>
#define maxn 100001
using namespace std;
int n,len=0;
int a[maxn],f[maxn],pre[maxn],t[maxn];
int bound(int x)
{
    int L=1,R=len;
    while(L<R){
        int mid=(L+R)>>1;
        if(a[f[mid]]>x) R=mid;
        else L=mid+1;
    }
    return L;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[f[len]]<a[i]){
            f[++len]=i;
            pre[i]=f[len-1];
        }
        else{
            int b=bound(a[i]);
            f[b]=i;
            pre[i]=f[b-1];
        }
    }
    int x=f[len];
    for(int i=1;i<=len;i++){
        t[i]=x;
        x=pre[x];
    }
    cout<<len<<endl;
    for(int i=len;i>=1;i--){
        if(i==len) cout<<a[t[i]];
        else cout<<" "<<a[t[i]];
	}
    cout<<endl;
    return 0;
}