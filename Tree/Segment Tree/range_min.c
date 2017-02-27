#include <stdio.h>
#include <math.h>

#define INF 1000000
#define minValue(a, b) ((a)<(b)?(a):(b))

int BuildST( int *st, int array[], int start, int end , int index){
	if( start == end ){
		st[index] = array[start];
		return st[index];
	}

	int mid = (start + end )/2;
	st[index] = minValue( BuildST( st, array, start, mid, 2*index + 1 ), BuildST( st, array, mid + 1, end, 2*index+2) );
	return st[index];
}
int getminfun( int *st, int ss, int se, int qs, int qe, int index){
	if( qs <= ss && qe >= se) //if node completely within range
		return st[index];
	else if( se < qs || ss > qe ) // if node is outside the range
		return INF;
	else{
		int mid = (ss + se)/2;
		return minValue( getminfun( st, ss, mid, qs, qe, 2*index +1 ), getminfun( st, mid + 1, se, qs, qe, 2*index + 2 ) );
	}
}

int getmin(int *st, int start, int end, int size){
	if( start < 0 || end >= size || start > end ){
		printf("Invalid Input query");
		return -1;
	}

	return getminfun(st, 0, size-1, start, end, 0);
}

void updatefun( int *st , int ss, int se, int st_index, int index , int value){
	if( index < ss || index > se )
		return;
	//st[st_index] = st[st_index] + diff;
	if( st[st_index] > value)
		st[st_index] = value;
	if( ss == se )
		st[st_index] = value;
	else { //untill the last node (leaf) is node found
		int mid = (ss + se)/2;
		updatefun( st, ss, mid, 2*st_index + 1, index, value);
		updatefun( st, mid + 1, se, 2*st_index + 2, index, value);
	} 
}

void update(int array[], int *st, int size, int index, int value ){
	if( index < 0 || index >= size) 
		return;
	array[index] = value; 
	updatefun( st, 0, size-1, 0, index, value);
}

int main(){
	int i;
	int array[] = {1, 3, 5, 7, 9, 11};
	int size = sizeof(array)/sizeof(array[0]);

	int max_size = (int)(ceil(log2(size))); //height of segment tree
	int st[max_size];
	BuildST( st, array, 0, size-1, 0 );

	for( i = 0 ; i < max_size; i++ ){
		printf("i = %d %d\n", i, st[i] );
	}

	printf("getmin(1,3)%d\n", getmin(st, 1, 3, size));
	printf("getmin(3,5)%d\n", getmin(st, 3, 5, size));
	printf("getmin(1,5)%d\n", getmin(st, 1, 5, size));
	printf("getmin(2,4)%d\n", getmin(st, 2, 4, size));
	printf("getmin(1,6)%d\n", getmin(st, 1, 6, size));
	printf("getmin(2,2)%d\n", getmin(st, 2, 2, size));

	update(array, st, size, 2, 10);

	for( i = 0 ; i < max_size; i++ ){
		printf("i = %d %d\n", i, st[i] );
	}

	printf("getmin(2,2)%d\n", getmin(st, 2, 2, size));
	return 0;
}