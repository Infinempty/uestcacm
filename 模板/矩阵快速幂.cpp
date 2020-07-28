#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
const int maxn=105;
int n;//Î¬Êý 
struct Matrix {
	ll v[maxn][maxn];
	
	Matrix() {}
	Matrix(ll x) {
		init();
		for (int i = 0; i < maxn; i++) 
			v[i][i] = x;
	}
	void init() {
		memset(v, 0, sizeof(v));
	}
	Matrix operator *(Matrix const &b) const {
		Matrix c;
		c.init();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					c.v[i][j] = (c.v[i][j] + (ll)v[i][k]*b.v[k][j]) % MOD;
		return c;
	}
	Matrix operator ^(int b) {
		Matrix a = *this, res(1);
		while (b) {
			if (b & 1)
				res = res * a;
			a = a * a;
			b >>= 1;
		}
		return res;
	}
}A;
