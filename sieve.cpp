#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> prime; //this vector will contain prime numbers till n
vector<bool> sieve( int n )
{
	vector<bool> isprime(n+1, true); //isprime[i] is true if i is a prime
	isprime[0] = isprime[1] = false; //0 and 1 are not prime
	int m = sqrt(n);

	for( int i = 2; i <= m ; i++ )
		if( isprime[i] )
			for( int k=i*i; k <= n ; k += i )
				isprime[k] = false;

	prime.push_back(2);
	for( int i = 3; i <= n ; i+=2 ) //check only for odd numbers
		if( isprime[i] )
			prime.push_back(i);
	return isprime;
}

int main()
{
	int n = 100; 
	vector<bool> isprime;
	isprime = sieve(n);
	for(int i = 0 ; i < prime.size(); i++)
		cout<<prime[i]<<" ";
	cout<<endl;
	cout<<isprime[23]<<endl;  //checking if 23 is prime or not
	return 0;
}