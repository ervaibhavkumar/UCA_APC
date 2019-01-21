#include <stdio.h>
#include <stdlib.h>

int ** getSpiral(int n) {
	int **arr = (int **)malloc(sizeof(int *) * n);
	for(int i=0;i<n;i++) {
		arr[i] = (int *)malloc(sizeof(int) * n);
	}
	int num = 1;
	int top = 0 , left = 0;
	int right = n-1 , bottom = n-1;
	while(num<=n*n) {
		for(int i=left;i<=right;i++) {
			arr[top][i] = num;
			num++;
		}
		top++;
		if(top>bottom) break;
		for(int i=top;i<=bottom;i++) {
			arr[i][right] = num;
			num++;
		}
		right--;
		for(int i=right;i>=left;i--) {
			arr[bottom][i] = num;
			num++;
		}
		bottom--;
		for(int i=bottom;i>=top;i--) {
			arr[i][left] = num;
			num++;
		}
		left++;
		if(left>right) break;
	}
	return arr;
}

int main()
{
	int n = 3;
	int **arr = (int **)malloc(sizeof(int *) * n);
	for(int i=0;i<n;i++) {
		arr[i] = (int *)malloc(sizeof(int) * n);
	}
	arr = getSpiral(n);
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}