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
	int c[l];

	for(int i=0;i<l;i++)
	{
		c[i]=(str[i]-'a'+key[i%m]-'a')%26;
	}

	cout<<"encryption text"<<endl;
	for(int i=0;i<l;i++)
	{
	cout<<char(c[i]+65)<<" ";
	}

	cout<<endl;
	
	int d[l];
	for(int i=0;i<l;i++)
	{
		int temp;
		temp=(c[i]-(key[i%m]-'a') ) %26; 
		if(temp<0)
			d[i]=temp+26;
		else
			d[i]=temp;
	}
	cout<<"decryption msg"<<endl;

	for(int i=0;i<l;i++)
	{
		cout<<char(d[i]+65)<<" ";
	}
	
}
