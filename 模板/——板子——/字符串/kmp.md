```c++
#include<string>
#include<iostream>
using namespace std;
const int MAX = 2000010;
int nxt[MAX],ans[MAX];
string a, b;
void kmp() {
	string temp;
	temp += b;
	temp += '$';
	temp += a;
	for (int i = 1; i < temp.size(); i++) {
		int u = nxt[i - 1];
		while (u > 0 && temp[u] != temp[i])u = nxt[u - 1];
		if (temp[u] == temp[i])u++;
		nxt[i] = u;
	}
}
int main() {
	getline(cin, a);
	getline(cin, b);
	kmp();
	int cnt = 0;
	int k = b.size();
	for (int i = 1+k; i < a.size()+k+1; i++) {
		if (nxt[i] >= k)ans[cnt++] = i-2*k+1;
	}
	for (int i = 0; i < cnt; i++) {
		printf("%d ", ans[i]);
	}
}
```

