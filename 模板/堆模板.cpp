#include <iostream>
#include<iomanip>
#include<algorithm>
#define MOD 99999997
using namespace std;

int find_min(int *arr, int n, int r)
{
	int temp = n;
	if (2 * n + 1 <= r && arr[n] > arr[2 * n + 1])temp = 2 * n + 1;
	if (2 * n + 2 <= r && arr[temp] > arr[2 * n + 2])temp = 2 * n + 2;
	return temp;
}
void adjust_heap(int *arr, int n, int r)
{
	int temp = find_min(arr, n, r);
	if (temp != n)
	{
		swap(arr[n], arr[temp]);
		adjust_heap(arr, temp, r);
	}
}
void make_heap(int *arr, int l, int r)
{
	for (int i = r; i >= l; i--)
		adjust_heap(arr, i, r);
}
void heap_insert(int *arr,int num,int &r)
{
	r=r+1;
	arr[r]=num;
	for(int i=r;;i=(i-1)/2)
	{
		if(i<0)break;
		adjust_heap(arr,i,r);
		if(i==0)break;
	}
}
int heap_top(int *arr)
{
	return arr[0];
}
void heap_pop(int *arr,int &r)
{
	swap(arr[0],arr[r]);
	r--;
	adjust_heap(arr,0,r);
}
//  *这里的排序应根据需求更改 
void heap_sort(int *arr,int &r)
{
	while(r>=0)
	{
		cout<<heap_top(arr)<<" ";
		heap_pop(arr,r);
	}
}
int heap[100050];
int main()
{
	long long ans=0,temp;
	int n=10,r;
	cin>>n;
	r=n-1;
	for(int i=0;i<n;i++)cin>>heap[i];
	make_heap(heap,0,n-1);
	heap_sort(heap,r);
	return 0;
}
