#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int rotated(int *arr , int n , int key) {
	int i;
	int pivot = n , min = INT_MAX;
	for(i=0;i<n;i++) {
		if(min>arr[i]) {
			pivot = i;
			min = arr[i];
		}
	}
	// return pivot;

	int left = -1 , right = -1;
	if(arr[pivot-1] > key && arr[n-1]>=key) {
		left = pivot-1;
		right = n;
	}
	else {
		left = 0;
		right = pivot-1;
	}

	while(left<=right) {
		// printf("%d %d\n",left,right );
		int mid = (left+right)/2;
		if(arr[mid]==key) return mid;
		else if(arr[mid] > key) right = mid - 1;
		else left = mid + 1;
	}
}

int main()
{
	int arr[] = {4,5,1,2};
	int tar = 1;
	int n = 4;
	printf("%d\n",rotated(arr,n,tar));
	return 0;
}