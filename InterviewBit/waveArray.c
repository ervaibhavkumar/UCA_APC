#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a , const void *b) {
	return (*(int *)a - *(int *)b);
}

void waveArray(int *arr , int n) {
	qsort(arr,n,sizeof(int),cmp);
	for(int i=0;i<n-1;i+=2) {
		int temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
	}
}

int main()
{
	int arr[] = {5,1,3,2,4};
	int n = 5;
	waveArray(arr,n);
	for(int i=0;i<n;i++) {
		printf("%d\n",arr[i]);
	}
	return 0;
}