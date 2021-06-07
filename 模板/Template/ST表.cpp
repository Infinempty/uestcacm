#include<bits/stdc++.h>
#define maxn 50010
using namespace std;
int a[maxn],st1[maxn][20],st2[maxn][20];
void RMQ1(int n)
{
    for(int i=1;i<=n;i++) st1[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++) for(int i=1;i+(1<<j)-1<=n;i++) st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
    return;
}
int query1(int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1) k++;
    return max(st1[l][k],st1[r-(1<<k)+1][k]);
}
void RMQ2(int n)
{
    for(int i=1;i<=n;i++) st2[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++) for(int i=1;i+(1<<j)-1<=n;i++) st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
    return;
}
int query2(int l, int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1) k++;
    return min(st2[l][k],st2[r-(1<<k)+1][k]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    RMQ1(n);
    RMQ2(n);
    for(int i=1;i<=m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",query1(l,r)-query2(l,r));
    }
    return 0;
}
