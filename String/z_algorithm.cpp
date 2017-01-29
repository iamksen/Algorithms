#include <bits/stdc++.h>
using namespace std;

vector<int> Z;

void calculate_z(string x)
{
	int len = x.length();
	Z.clear();
	Z.resize(len);

	int L = -1, R = -1;
	Z[0] = 0;
	for(int i = 1; i < len; i++){
		if( i > R){
			L = R = i;
			while( R < len && x[R] == x[R-L])
				R++;
			Z[i] = R-L;
			R--;
		} else {
			if( Z[i-L] < R-i+1)
				Z[i] = Z[i-L];
			else if( Z[i-L] > R-i+1)
				Z[i] = R-i+1;
			else {
				L = i;
				while(R<len && x[R] == x[R-L])
					R++;
				Z[i] = R-L;
				R--;
			}
		}
	}
}

int main()
{
	string text, pattern;
	cin>>pattern;
	cin>>text;
	
	string temp = pattern + "$" + text;
	calculate_z(temp);

	//Print index where pattern matched in text
	for(int i = pattern.length()+1 , j = 0; i < temp.length(); i++, j++)
		if( Z[i] == pattern.length())
			cout<<j<<endl;
	return 0;
}
