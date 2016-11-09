#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ull;

//This function print all the indices of the pattern in str
void rabin_karp(string str, string pattern)
{
	//For lowercase letter choose p=31, for uppercase p=53
	const int p = 31;

	vector<ull> p_pow( max(pattern.length(), str.length()) );

	//Calculate all power of p
	p_pow[0] = 1;
	for(size_t i = 1; i < p_pow.size(); i++)
		p_pow[i] = p_pow[i-1]*p;
	
	//Calculate hashes of all prefixes of text str
	vector<ull> h(str.length());
	for( size_t i = 0 ; i < str.length(); i++){
		h[i] = (str[i] - 'a' + 1)*p_pow[i];
		if(i)
			h[i] += h[i-1];
	}

	//calculate the hash of the pattern
	ull h_s = 0;
	for(size_t i = 0 ; i < pattern.length(); i++)
		h_s += (pattern[i] - 'a' + 1)*p_pow[i];
	
	//Iterate over all substring of str having lenght |pattern| and compare them with str
	for(size_t i = 0 ; i + pattern.length() - 1 < str.length(); i++){
		ull cur_h = h[i+pattern.length()-1];
		if(i)
			cur_h -= h[i-1];
		if(cur_h == h_s*p_pow[i])
			cout<<i<<" "; //Print the matching index
	}

}

int main()
{
	string pattern, str; //str is text and pattern is the pattern to be matched with str
	cin>>str>>pattern;
	rabin_karp(str, pattern);
	return 0;
}
