#include <stdio.h>
#include <stdlib.h>

void zigzag(int **arr , int n) {
	int even = 0 , odd = 1;
	while(even < n) {
		for(int i=0;i<n;i++) {
			printf("%d\n",arr[even][i]);
		}
		even += 2;
		if(odd < n) {
			for(int i=n-1;i>=0;i--) {
				printf("%d\n",arr[odd][i]);
			}
		}
		odd += 2;
	}
}

int main()
{
	int n = 3;
	int **arr = (int **)malloc(sizeof(int *) * n);
	for(int i=0;i<n;i++) {
		arr[i] = (int *)malloc(sizeof(int) * n);
	}
	int num = 1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			arr[i][j] = num++;
		}
	}
	zigzag(arr,n);
	return 0;
}