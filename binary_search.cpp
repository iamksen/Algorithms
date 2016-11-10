#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*This function returns the index of target if present in sorted vector else return -1*/
int binary_s(int target, vector<int> v)
{
	//sort(v.begin(), v.end()); //if v is not sorted before calling binary_s()
	int mid, low = 0, high = v.size();
	while( low < high ){
		mid = low + (high-low+1)/2; //+1 to round off 
		if( target == v[mid])
			return mid;
		else if( v[mid] < target)
			low = mid+1;
		else
			high = mid-1;
	}
	return -1; //if target is not found in v
}

int main()
{
	int index, target = 4;
	int array[] = {1,2,3,4,5,4,3,2,1};
	vector<int> v(array, array+9);
	sort( v.begin(), v.end() );
	
	index = binary_s( target, v);
	if( index != -1 )
		cout<<index<<endl;
	else
		cout<<"Not found\n";

	/*STL binary_search() return true is target is present else return false*/
	if( binary_search( v.begin(), v.end(), target))
		cout<<"Found\n";
	else
		cout<<"Not found\n";
	
	return 0;
}
