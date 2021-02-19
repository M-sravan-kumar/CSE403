#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string str;
	string key;
	cin>>str;
	cin>>key;
	int l=str.length();
	int m=key.length();
	int res[l];
	
	// ((int(p[i]-96) )+ (int (k[i]-96))) %26 + 96

	if(l!=m)
		cout<<"not possible";
	else
	{
		for(int i=0;i<l;i++)
		{
		res[i]=str[i]-'A'+key[i]-'A';
		}
		cout<<"encrypted msg"<<endl;
		// input :- RAMSWARUPK
		// key :-RANCHOBABA
		// I A Z U D O S U Q K
		for(int i=0;i<l;i++)
		{
			cout<<char((res[i]%26+65))<<" ";
		}
		cout<<endl;

		cout<<"decrypted msg"<<endl;
		
		for(int i=0;i<l;i++)
		{
			cout<< char(res[i]-(key[i]-'A')+65 )<<" ";
		}
	}
}
	
