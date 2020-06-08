#include<bits/stdc++.h>
#define ll long long
using namespace std; 
//set类可以进行自动排序 不妨多加利用 
struct Node
{	
	ll l,r;
	bool operator <(const Node& rhs)const
	{
		return r<rhs.l;
	}
	
	Node(){}
	Node(ll l_,ll r_):l(l_),r(r_){}
};
set<Node> s;
int main()
{
	int n;
	ll l,r;
	scanf("%d",&n);
	scanf("%lld %lld",&l,&r);
	Node in(l,r),temp,ans;
	s.set::insert(in);
	cout<<s.size()<<" ";
	set<Node>::iterator it;
	for(int i=1;i<n;i++)
	{
		cin>>l>>r;
		in.l=l;in.r=r;
		it=s.find(in);
		if(it==s.set::end())s.set::insert(in);
		else 
		{
			ans=*it;
			s.erase(it);
			ans.l=min(ans.l,in.l);
			ans.r=max(ans.r,in.r);
			it=s.find(ans);
			while(it!=s.set::end())
			{
				temp=*it;
				s.erase(it);
				ans.l=min(temp.l,ans.l);
				ans.r=max(temp.r,ans.r);
				it=s.find(ans);
			}
			s.set::insert(ans);
		}
		cout<<s.size()<<" ";
	}
}
