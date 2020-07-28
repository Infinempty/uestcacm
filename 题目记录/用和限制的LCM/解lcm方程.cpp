#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double eps=1e-5;
const double pi=acos(-1.0);
const int MOD=1e9+7;
const int maxn=1000005;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    ll a,b;
    while(cin>>a>>b)
    {
        ll c=gcd(a,b)*b;
        ll x=(a-sqrt(a*a-4*c))/2;
        ll y=a-x;
        ll k=gcd(x,y)*b;
        if(x*y==k)
            cout<<x<<" "<<y<<endl;
        else
            cout<<"No Solution"<<endl;
    }
    return 0;
}