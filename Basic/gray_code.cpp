#include <bits/stdc++.h>
using namespace std;

int gray_code( int n )
{
	return n^(n>>1);
}

int rev_gray_code( int g )
{
	int n = 0;
	for(; g ; g >>= 1)
		n ^= g;
	return n;
}

int main()
{
	cout<<gray_code(4)<<endl;
	cout<<rev_gray_code(4)<<endl;
	return 0;
}
