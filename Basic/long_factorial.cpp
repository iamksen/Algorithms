#include <stdio.h>
int main()
{
	int t,n,i,temp,carry,digit=0,j;
	int fact[200]={0};
	scanf("%d",&n);
	temp=1; digit=1; carry=0;
	fact[0]=1;
	for(i=1;i<=n;i++){
		carry=0;
		for(j=0;j<digit;j++){
			temp = fact[j]*i+carry;;
			fact[j] = temp%10;
			carry = temp/10;
		}
		while(carry>0){
			fact[digit++] = carry%10;
			carry /= 10;
	        }
	}
	for(i=digit-1;i>=0;i--)
		printf("%d",fact[i]);
	printf("\n");
	
	return 0;
}