#include <stdio.h>
#include <stdlib.h>

void merge(int *a , int L , int mid , int R) {
	int *aux = (int*)malloc(sizeof(a));

	int i = L , j = mid+1 , k=0;
	while(i<=mid && j<=R) {
		if(a[i]<a[j]) {
			aux[k++] = a[i++];
		}
		else {
			aux[k++] = a[j++];
		}
	}
	while(i<=mid) {
		aux[k++] = a[i++];
	}
	while(j<=R) {
		aux[k++] = a[j++];
	}
	for(i=L,j=0;i<=R;i++,j++) {
		a[i] = aux[j];
	}
}

void mergeSort(int *arr , int L , int R) {
	if(L==R) return;
	int mid = (L+R)/2;
	mergeSort(arr , L , mid);
	mergeSort(arr,mid+1,R);
	merge(arr, L , mid , R);
}

int main()
{
	// int arr[] = {5,1,7,234,9,2};
	int arr[] = {1,2,3,5,3,4};
	int n = 6;
	mergeSort(arr,0,5);
	for(int i=0;i<n;i++) {
		printf("%d\n",arr[i]);
	}
	return 0;
}