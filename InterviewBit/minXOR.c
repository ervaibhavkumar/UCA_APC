#include <stdio.h>
#include<stdlib.h>
#include <limits.h>

int comp(const void *a , const void *b) {
	return (*(int*) a) - (*(int*)b);
}

int minXor(int *a , int n) {
	qsort(a,n,sizeof(int),comp);
	int min = INT_MAX,i;
	for(i=1;i<n;i++) {
		int temp = a[i] ^ a[i-1];
		// printf("%d\n",temp);
		if(temp<min) min = temp;
	}
	return min;
}

int main()
{
	int arr[] = {0,2,5,7};
	int n = 4;
	printf("%d\n",minXor(arr,n));
	return 0;
}