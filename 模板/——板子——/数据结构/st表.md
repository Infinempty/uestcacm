查询定区间最大值

```c++
#include<bits/stdc++.h>
using namespace std;
int st[100010][22];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        st[i][0]=read();
    }
    for (int j = 1; j < 22; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= N; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        }
    }
    while (M--)
    {
        int l=read(), r=read();
        int k = (int)log2(r - l + 1);
        cout << max(st[l][k], st[r - (1 << k) + 1][k]) << '\n';
    }
    return 0;
}

```

