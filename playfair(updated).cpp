#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removeDuplicatesFromString(string str)
{
    int counter = 0;
    int i = 0;
    int size = str.size();
    int x;
    int length = 0;
    while (i < size) {
        x = str[i] - 97;
 
         if ((counter & (1 << x)) == 0) {
 
            str[length] = 'a' + x;
            counter = counter | (1 << x);
 
            length++;
        }
        i++;
    }
    return str.substr(0, length);
}

pair<int,int> searchindex(char s,char a[][5])
{
	int x,y;
	pair<int,int> p;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(a[i][j]==s)
			{
				x=i;
				y=j;
				break;
			}
		}
	}
	p.first=x;
	p.second=y;
	return p;
}

pair<char,char> encrypt(char ch1,char ch2,char arr[][5])
{
	pair<int,int> p1=searchindex(ch1,arr);
	pair<int,int> p2=searchindex(ch2,arr);

	pair<char,char> p3;

	if(p1.first==p2.first)
	{
		p3.first=arr[p1.first][(p1.second+1)%5];
		p3.second=arr[p2.first][(p2.second+1)%5];
	}
	else if(p1.second==p2.second)
	{
		p3.first=arr[(p1.first+1)%5][p1.second];
		p3.second=arr[(p2.first+1)%5][p2.second];
	}
	else
	{
		p3.first=arr[p1.first][p2.second];
		p3.second=arr[p2.first][p1.second];
	}

	return p3;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string str,str2;
	cin>>str;
	cin>>str2;
	int l=str.length();
	char res[l+1];

	char alpha[26]={'A','B','C','D','E','F','G','H','I','J','K',
	'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	int l2=str2.length();
// removing duplicates
	
	string modifiedstring = removeDuplicatesFromString(str2);
	cout<<endl<<"after removing duplicates"<<endl;
	cout<<modifiedstring<<endl;
	// pairing 
	int check[26]={0};
	for(int i=0;i<l;i=i+2)
	{
		res[i]=str[i];
		if(str[i+1]){
			if(str[i]==str[i+1])
			{
				res[i+1]='X';
			}
			else
			{
				res[i+1]=str[i+1];
			}
		}
		else
		{
			res[i+1]='X';
		}
	}


	// making 1's
	for(int i=0;i<l2;i++)
	{
		check[str2[i]-'A']=1;
	}

	// for(int i=0;i<26;i++)
	// {
	// 	cout<<check[i]<<' ';
	// }
	cout<<endl;
	char arr[5][5];
	int c=0;
	int flag=1;

	int i=0,j;
	int ml=modifiedstring.length();
	while(i<5)
	{
		j=0;
		while(j<5)
		{
			if(c<ml){
				arr[i][j]=modifiedstring[c];
				c++;
				j++;
			}
			else
			{
				break;
			}
		}
		i++;
	}

	i=ml/5;
	j=ml%5;
	// cout<<i<<' '<<j<<endl;
	int p=0;
	while(i<5)
	{
		while(j<5)
		{
			if(check[p]==0 and p!=9){
				arr[i][j]=alpha[p];
				j++;
				check[p]=1;
			}
			else
				p++;
		}
		j=0;
		i++;
	}



	cout<<"matrix:-"<<endl;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<arr[i][j]<<' ';
		// 	arr[i][j]=alpha[p];
		// 	p++;
		// }
		}
		cout<<endl;
	}
	cout<<endl;
	
	cout<<"modifiedstring is :-"<<endl;
	int len;
	if(l%2==0)
		len=l;	
	else
		len=l+1;
	for(int i=0;i<len;i++)
	{
		cout<<res[i];
	}
	char ciphertext[len];
	
	for(int i=0;i<len;i=i+2)
	{
		pair<char,char> cp=encrypt(res[i],res[i+1],arr);
		ciphertext[i]=cp.first;
		ciphertext[i+1]=cp.second;
	}

	cout<<endl<<endl;
	cout<<"ciphertext is:-"<<endl; 
	for(int i=0;i<len;i++)
	{
		cout<<ciphertext[i];
	}


}