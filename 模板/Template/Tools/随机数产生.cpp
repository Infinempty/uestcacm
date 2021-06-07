#include<bits/stdc++.h>
using namespace std;
int a[100];
signed main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    default_random_engine e; 
    e.seed(unsigned(time(0)));
    uniform_int_distribution<unsigned> u(-3,3);
    for(int i=1;i<=30;i++) a[i]=90;
    for(int i=1;i<=30;i++) a[i]+=u(e);
    for(int i=1;i<=30;i++) printf("%d\n",a[i]);
    return 0;
}
//mt19937_64
mt19937_64 rand_num(chrono::system_clock::now().time_since_epoch.count());