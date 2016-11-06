#include <iostream>
using namespace std;

int gcd( int a, int b ) 
{
	if( b == 0 )
		return a;
	else
		return gcd(b, a%b);
}

int main() 
{
	cout<<"Program to calculate gcd of two numbers";
	int firstno, secondno;
	cin>>firstno>>secondno;
	cout<<gcd(firstno, secondno)<<endl;
	return 0;
}