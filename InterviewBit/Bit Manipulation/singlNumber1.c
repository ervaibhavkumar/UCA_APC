#include <stdio.h>
#include <stdlib.h>

int singleNumber1(int *a , int n) {
	int num = a[0] ^ a[1] , i;
	for(i=2;i<n;i++) num = num ^ a[i];
	return num;
}

int main()
{
	int arr[] = {1,2,2,3,1};
	int n = 5;
	printf("%d\n",singleNumber1(arr,n));
	return 0;
}