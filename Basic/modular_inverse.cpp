// apply only when A and M are coprime
#include <iostream>
using namespace std;
#define MOD 1000000007

int d, x, y;
void extendedEuclid(int A, int B) //Ax + By = GCD(A, B)
{
	if( B == 0 ){
		d = A;
		x = 1;
		y = 0;
	} else {
		extendedEuclid(B, A%B);
		int temp = x;
		x = y;
		y = temp - (A/B)*y;
	}
}

int binary_exponentiation(int A, int B)
{
	int result = 1;
	while(B>0){
		if(B&1)
			result = (result*A)%MOD;
		A = (A*A)%MOD;
		B = B>>1;
	}
	return (result%MOD);
}

//An inverse exists only when A and MOD are coprime i.e. GCD(A,MOD)=1
int modInverse(int A)
{
	extendedEuclid(A,MOD);
	return (x%MOD + MOD)%MOD;

	//use only when M is prime
	return binary_exponentiation(A, MOD-2);
}

int main()
{
	cout<<modInverse(10);	
	return 0;
}
