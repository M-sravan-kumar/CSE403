#include<bits/stdc++.h>  
#include<iostream>  
using namespace std;

pair<int,int> ciphering(char a, char b,int A[][2])
{
	pair<int,int> p;
	int B[2][1];
	B[0][0]=(a-'A')%26;
	B[1][0]=(b-'A')%26;

	int res[2][1];
	for(int i=0;i<2;i++)
	{
		res[i][0]=0;
		for(int j=0;j<2;j++)
		{	

			res[i][0]+=(A[i][j]*B[j][0])%26;
		}	
	}
	
	p.first=res[0][0];
	p.second=res[1][0];	

	return p;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int modulo_multiplicative_inverse(int A, int M){

	for(int i=0;i<M;i++)
	{
		if((A*i)%M==1)
				return i;
	}

    return -1;
} 

// input :-

// SHORTEXAMPLE
// HILL

// output :-

// key matrix is
// 7 8 
// 11 11 
// APADJTFTWLFJ

// determinant is 23
// inverse of determinant is 17
// 11 18 
// 15 7 



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	string plaintext,key;
	cin>>plaintext>>key;
	int A[2][2];
	int c=0;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			A[i][j]=key[c]-'A';
			c++;
		}
	}
	cout<<"key matrix is"<<endl;

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	
	int l=plaintext.length();
	int ciphertext[l];
	
	// encryption
	for(int i=0;i<l;i=i+2)
	{
		pair<int,int> t;
		t=ciphering( plaintext[i],plaintext[i+1] ,A);
		ciphertext[i]= t.first;
		ciphertext[i+1]=t.second;
	}

	for(int i=0;i<l;i++)
		cout<<char(ciphertext[i]%26+65);	
	// decryption 
	int A_inverse[2][2];
	A_inverse[0][0]=A[1][1];
	A_inverse[1][1]=A[0][0];
	A_inverse[0][1]=( A[0][1]-2*(A[0][1]) +26)%26;
	A_inverse[1][0]=( A[1][0]-2*(A[1][0]) +26)%26;
	cout<<endl;
	int d=A[0][1]-A[1][0];
	if(d<0)
		d+=26;
	cout<<endl<<"determinant is "<<d<<endl;
	cout<<"inverse of determinant is "<<modulo_multiplicative_inverse(d,26)<<endl;
	// cout<<gcd(23,26)<<endl;

	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<A_inverse[i][j]<<" ";
		}
		cout<<endl;
	}	


}	