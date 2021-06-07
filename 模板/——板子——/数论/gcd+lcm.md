```c++
#include<vector>
#include<iostream>
using namespace std;

int euclid(int a, int b) {
	if (b == 0)return a;
	return euclid(b, a % b);
}

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }


const int maxn = 100;
int nums[maxn];
int lcm() {
	int ans = nums[0];
	for (int i = 0; i < maxn - 1; i++) {
		ans = euclid(ans, nums[i+1]);
	}
	return ans;
}
```

