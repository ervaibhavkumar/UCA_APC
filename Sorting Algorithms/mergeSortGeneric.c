#include <stdio.h>
#include <stdlib.h>

void mergeSort(void *a[] , void *aux[] , int l , int r , int (*cmp)(void * , void *)) {
	if(l==r) return;
	int mid = (l+r)/2;
	mergeSort(a,aux,l,mid,cmp);
	mergeSort(a,aux,mid+1,r,cmp);
	merge(a,aux,l,mid,r,cmp);
}

void merge(void *a[] , void *aux[] , int l , int mid , int r , int (*cmp)(void * , void *)) {
	int i = l , j = mid+1 , k=0;
	while(i<=mid && j<=r) {
		if((*cmp)(a[i],a[j]) > 0) {
			aux[k++] = a[i++];
		}
		else {
			aux[k++] = a[j++];
		}
	}
	while(i<=mid) {
		aux[k++] = a[i++];
	}
	while(j<=r) {
		aux[k++] = a[j++];
	}
	for(i=l,j=0;i<r;i++,j++) {
		a[i] = aux[j];
	}
}

int intcmp(int *x , int *y) {
	return (*x)>(*y) ? 1 : 0;
}

int main()
{
	int arr[] = {4 , 2, 56, 21 , 29 , 1 ,2};
	int n = 7;
	int *aux = (int*)malloc(sizeof(int)*n);
	mergeSort((void *)arr , aux , 0 , n-1 , intcmp);
	for(int i=0;i<n;i++) {
		printf("%d\n",arr[i]);
	}
	return 0;
}