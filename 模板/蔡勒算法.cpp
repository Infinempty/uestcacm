#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int zeller(int year,int month,int day){
	if(month==1||month==2){
		month+=12;
		year-=1;
	}
	int c=year/100;
	int y=year-c*100;
	int week=y+y/4+c/4-2*c+26*(month+1)/10+day-1;
	return (week+7)%7;
}
