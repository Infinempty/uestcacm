#include<iostream>
#include<string.h>
#define next m_next
#define ll long long
using namespace std;

int next[1000050];
int main()
{
	int j=0;
	string t,s;
	cin>>s>>t;
	t=" "+t;
	s=" "+s;
	next[1]=0;
	for(int i=2;i<t.length();i++)
	{
		j=next[i-1];
		while(j&&t[i]!=t[j+1])j=next[j];
		if(t[i]==t[j+1])j++;
		next[i]=j;
	}
	j=0;
	for(int i=1;i<s.length();i++)
	{
		while(j&&s[i]!=t[j+1])j=next[j];
		if(s[i]==t[j+1])j++;
		if(j==t.length()-1)cout<<i-t.length()+2<<" ";
	}
	return 0;
}