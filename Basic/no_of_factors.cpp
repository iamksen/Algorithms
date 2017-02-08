#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

typedef vector<int> vi;

vi prime;
vector<bool> tick(10000001, true);
void sieve(int n)
{
	tick[0] = tick[1] = false;
	for(int i = 4 ; i <= n ; i+=2)
		tick[i] = false;

	for(int i = 3; i <= sqrt(n); i+=2){
		if( tick[i] ){
			for(int j = i*i; j <= n; j += i )
				tick[j] = false;
		}
	}
	prime.pb(2);
	for(int i = 3; i <= n; i += 2 )
		if( tick[i] )
			prime.pb(i);
}

int main()
{
	int i, n, value, count;
	long long result;
	sieve(10000000);
	int size = (int)prime.size();
	cin>>n; //total no of numbers
	while(n--){
		cin>>value; //no whose no of factors are to be calculated
		if(value < 1000000 && tick[value]){ cout<<"2\n"; continue; }
		i = 0;
		result = 1;
		while( value > 1){
			count = 0;
			while( value%prime[i] == 0){
				count++;
				value = value/prime[i];
			}
			result = result*(count+1);
			i++;
			if( i >= size ) break;
		}
		if( value > 1 )
		    result = result*2;
		cout<<result<<endl;
	}
	return 0;
}
