#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a , const void *b) {
	return (*(int *)a - *(int *)b);
}

int noble(int *arr , int n) {
	qsort(arr,n,sizeof(int),cmp);
	for(int i=0;i<n;i++) {
		if(arr[i] == n - i - 1) return arr[i];
	}
	return -1;
}

int main()
{
	int arr[] = {10, 3, 20, 40, 2};
	int n = 5;
	printf("%d\n",noble(arr,n));
	return 0;
}