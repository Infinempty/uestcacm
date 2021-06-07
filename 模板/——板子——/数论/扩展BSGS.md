```c++
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<math.h>
#define ll long long
#define pr pair<ll,ll>

using namespace std;
unordered_map<ll, ll> Map;
ll ans;
pr ex_euclid(ll a, ll b) {
	if (b == 0) {
		ans = a;
		return { 1,0 };
	}
	pr tmp = ex_euclid(b, a % b);
	return { tmp.second,tmp.first - (a / b) * tmp.second };
}
ll modsolver(ll a, ll b, ll n) {
	pr p = ex_euclid(a, n);
	if (b % ans == 0) {
		return (p.first * b / ans) % n;
	}
	return 0;
}

//A^X=B(mod C)求X C为整数
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll a, b, c, cnt;
ll k;
ll precal() {
	if (b == 1)return 0;
	k = 1;
	ll g;
	cnt = 0;
	ll tb = b, tc = c;
	while ((g = gcd(a, c)) > 1) {
		if (b % g)return -1;
		b /= g;
		c /= g;
		k =(k* a / g)%c;
		cnt++;
	}
	if (cnt) {
		k = (modsolver(k, 1, c) + c) % c;
		b = (b * k) % c;
	}
	else return -2;
	ll tmp = 1;
	for (int i = 0; i <= cnt; i++) {
		if (tmp % tc == tb)return i;
		tmp *= a;
		tmp %= tc;
	}
	return -2;
}
ll BSGS()
{
	if (b == 1)
		return 0;
	Map.clear();
	int m = (int)sqrt(c *1.0);
	ll x = 1, p = 1;
	for (ll i = 0; i < m; ++i, p = p * a % c)
		Map[p * b % c] = i;
	unordered_map<ll, ll>::iterator it;
	for (ll i = m; ; i += m)
	{
		it = Map.find(x = x * p % c);
		if (it != Map.end())
			return i - it->second;
		if (i > c)
			break;
	}
	return -1;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		a %= c;
		if (!a)break;
		ll tmp = precal();
		if (tmp == -1)cout << "QAQ" << '\n';
		else if (tmp >= 0)cout << tmp << '\n';
		else {
			ll ans = BSGS();
			if (ans == -1)cout << "QAQ" << '\n';
			else cout << ans + cnt << '\n';
		}
	}
	return 0;
}
```

