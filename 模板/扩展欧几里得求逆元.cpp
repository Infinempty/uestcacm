#include<bits/stdc++.h>
#define ll long long 
using namespace std;

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	//ax+by=gcd(a,b) 
    if(b==0)
    {
        x=1;y=0;
        return a;
    }
    ll r=exgcd(b,a%b,x,y);
    ll temp=y;
    y=x-(a/b)*y;
    x=temp;
    return r;
}
ll inv(ll a,ll b){
    ll x,y;
    exgcd(a,b,x,y);
    return (x%b+b)%b;
}
