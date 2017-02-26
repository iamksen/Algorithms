#include <stdio.h>
#include <math.h>

int BuildST( int *st, int array[], int start, int end , int index){
	if( start == end ){
		st[index] = array[start];
		return st[index];
	}

	int mid = (start + end )/2;
	st[index] = BuildST( st, array, start, mid, 2*index + 1 ) + BuildST( st, array, mid + 1, end, 2*index+2);
	return st[index];
}
int getSumfun( int *st, int ss, int se, int qs, int qe, int index){
	if( qs <= ss && qe >= se) //if node completely within range
		return st[index];
	else if( se < qs || ss > qe ) // if node is outside the range
		return 0;
	else{
		int mid = (ss + se)/2;
		return getSumfun( st, ss, mid, qs, qe, 2*index +1 ) + getSumfun( st, mid + 1, se, qs, qe, 2*index + 2 );
	}
}

int getSum(int *st, int start, int end, int size){
	if( start < 0 || end >= size || start > end ){
		printf("Invalid Input query");
		return -1;
	}

	return getSumfun(st, 0, size-1, start, end, 0);
}

void updatefun( int *st , int ss, int se, int st_index, int index , int diff){
	if( index < ss || index > se )
		return;
	st[st_index] = st[st_index] + diff;
	if( ss != se ){ //untill the last node (leaf) is node found
		int mid = (ss + se)/2;
		updatefun( st, ss, mid, 2*st_index + 1, index, diff);
		updatefun( st, mid + 1, se, 2*st_index + 2, index, diff);
	} 
}

void update(int array[], int *st, int size, int index, int value ){
	if( index < 0 || index >= size) 
		return;
	int diff = value - array[index];
	array[index] = value; 
	updatefun( st, 0, size-1, 0, index, diff);
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

	printf("getSum(1,3)%d\n", getSum(st, 1, 3, size));
	printf("getSum(3,5)%d\n", getSum(st, 3, 5, size));
	printf("getSum(1,5)%d\n", getSum(st, 1, 5, size));
	printf("getSum(2,4)%d\n", getSum(st, 2, 4, size));
	printf("getSum(1,6)%d\n", getSum(st, 1, 6, size));

	update(array, st, size, 2, 10);

	for( i = 0 ; i < max_size; i++ ){
		printf("i = %d %d\n", i, st[i] );
	}
	return 0;
}