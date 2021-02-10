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

	string plaintext;
	cin>>plaintext;
	int l=plaintext.length();
	char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K',
	'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	char encrypt[26]={'D','G','I','L','H','M','S','N','O','T','F',
		'P','E','J','R','V','A','Z','X','C','Q','W','Y','U','B','K'};

	cout<<"encryption message"<<endl;
	for(int i=0;i<l;i++)
	{
		cout<<encrypt[plaintext[i]-'A'];
	}

}