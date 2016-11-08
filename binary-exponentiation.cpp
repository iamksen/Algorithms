#include <iostream>
using namespace std;

long long bin_expo(long long a, long long b)
{
	long long result = 1;
	while(b){
		if(b&1)
			result = result*a;
		a = (a*a);
		b >>= 1;
	}
	return result;
}

int main()
{
	cout<<bin_expo(2,3)<<endl;
	cout<<bin_expo(3,2)<<endl;
	return 0;
}