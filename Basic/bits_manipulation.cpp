#include <bits/stdc++.h>
using namespace std;

int binary2int(string s) //convert a binary string into its decimal equivalent
{
	if( s == "0") return 0;
	int powerof2 = 1, number = 0;
	for(int i = s.length()-1 ; i >= 0; i--){
		if( s[i] == '1')
			number += powerof2;
		powerof2 = powerof2<<1;
	}
	return number;
}

string int2binary(int n) //returns binary representation of n
{
	string s = "";
	while(n){
		if(n&1)
			s = "1" + s;
		else 
			s = "0" + s;
		n = n>>1;
	}
	return s;
}

int bits_count(long long n) //returns total no of set bits in n; n>=0
{
	int count = 0;
	while(n){
		n = n&(n-1);
		count++;
	}
	return count;
}

int main()
{
	cout<<bits_count(2)<<endl;
	cout<<bits_count(10)<<endl;
	cout<<int2binary(6)<<endl;
	cout<<int2binary(16)<<endl;
	cout<<binary2int("1011")<<endl;
	cout<<binary2int("111")<<endl;
	return 0;
}
