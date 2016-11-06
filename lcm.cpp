#include <iostream>
using namespace std;

int gcd( int a, int b ) 
{
	if( b == 0 )
		return a;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b )
{
	return (a*b)/gcd(a,b); //take care of overflow; or use long long in place of int
}

int main() 
{
	cout<<"Program to calculate gcd of two numbers";
	int firstno, secondno;
	cin>>firstno>>secondno;
	cout<<lcm(firstno, secondno)<<endl;
	return 0;
}