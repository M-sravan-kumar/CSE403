#include<bits/stdc++.h>  
#include<iostream>  
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int r1,r2,q;
	cin>>r1>>r2;
	int s1=1,s2=0,t1=0,t2=1;
	int s,t,r;

	cout<<"q  r1 r2  r s1 s2  s  t1  t2  t"<<endl;
	while(true)
	{
		if(r2==0)
			break;
		q=r1/r2;
		r=r1%r2;
		s=s1-q*s2;
		t=t1-q*t2;
		r1=r2;
		r2=r;
		s1=s2;
		s2=s;
		t1=t2;
		t2=t;
		cout<<q<<"  "<<r1<<" "<<r2<<"  "<<r<<" "<<s1<<"  "<<s2<<"  "<<s<<"  "<<t1<<"  "<<t2<<"  "<<t<<endl;
	}	
	cout<<endl<<"GCD is "<<r1<<endl;
	cout<<"s1 and t1 are:- ";
	cout<<s1<<" "<<t1;

}