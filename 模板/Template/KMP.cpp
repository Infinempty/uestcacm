#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int n,m;
string s,t;
int Next[maxn];
int main()
{
    cin>>s>>t;//判断t在s中出现了几次
    n=s.size();
    m=t.size();
    Next[0]=0;
    for(int i=1;i<m;i++){
        int j=Next[i-1];
        while((t[j]!=t[i]) && (j>0)) j=Next[j-1];
        if(t[j]==t[i]) Next[i]=j+1;
        else Next[i]=0;
    }
    int i=0,j=0;
    while(i<n){
        if(s[i]==t[j]){
            i++;
            j++;
            if(j==m){
                printf("%d\n",i-m+1);
                j=Next[j-1];
            }
        }
        else{
            if(j==0) i++;
            else j=Next[j-1];
        }
    }
    for(int i=0;i<m;i++) printf("%d ",Next[i]);
    cout<<endl;
    return 0;
}
