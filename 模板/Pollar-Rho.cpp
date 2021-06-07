#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef __int128 lll;
typedef unsigned long long ull;
typedef long double ld;

struct Pollar_Rho{
	ull mul(ull a, ull b, ull p) {
		ll res = a * b - p * (ull)((ld)a * (ld)b );
		return res + p * (res < 0) - p * (res >= (ll)p);
	}
	ll mul(ll a, ll b, ll p) { return (lll)a * b % p; }
	ll qpm(ll a, ll b, ll p) {
    	ll r = 1;
    	do if (b & 1) r = mul(r, a, p);
    	while (a = mul(a, a, p), b >>= 1);
    	return r;
	}
	bool mr(ll n) {
    	if (n % 2 == 0) return n == 2;
    	if (n < 128) return (0X816D129A64B4CB6E >> (n / 2)) & 1;
    	const int l[15] = { 2, 11, 17, 325, 9375, 28178, 450775, 9780504, 1795265022 };
    	ll d0 = n - 1; do d0 >>= 1; while(!(d0 & 1));
   	 	for (ll a : l) {
   	  	    if (a % n == 0) return true;
      		ll d = d0, t = qpm(a, d, n);
        	while(d != n - 1 && t != 1 && t != n - 1)
        	    d <<= 1, t = mul(t, t, n);
        	if (t != n - 1 && !(d & 1)) return false;
    	}
   	 	return true;
	}
	ll gcd(ll a,ll b){
		return b==0? a:gcd(b,a%b);
	}
	ll pr(ll n) {
    	ll x = 0, y = 0, t = 1, q = 1, c = rand() % (n - 1) + 1;
    	for (int k = 2;; k <<= 1, y = x, q = 1) {
        	for (int i = 1; i <= k; ++i) {
            	x = (mul(x, x, n) + c) % n;
            	q = mul(q, abs(x - y), n);
            	if (!(i&127) && (t = gcd(q, n) > 1))
                	break;
        	}
        	if (t > 1 || (t = gcd(q, n)) > 1) break;
    	}
    	return t;
	}
	void pfd_pr(vector<ll>& ds, ll n) {
    	if (mr(n)) return ds.push_back(n);
    	ll p = n; while(p >= n) p = pr(n);
    	pfd_pr(ds, p); pfd_pr(ds, n / p);
	}

	void pfd(ll n,vector<ll> &v) {
		v.clear();
    	pfd_pr(v, n);
	}
}pr;