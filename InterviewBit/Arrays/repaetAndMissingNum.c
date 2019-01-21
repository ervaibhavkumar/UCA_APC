#include <stdio.h>
#include <stdlib.h>

int *getRes(int *arr , int n) {
	int *ans = (int *)malloc(sizeof(int) * 2);
	// int *temp = (int *)malloc(sizeof(int) * (n+1));
	// for(int i=0;i<n;i++) temp[i] = 0;
	// for(int i=0;i<n;i++) {
	// 	if(temp[arr[i]] == 0) {
	// 		temp[arr[i]] = 1;
	// 	}
	// 	else if(temp[arr[i]] == 1) {
	// 		ans[0] = arr[i];
	// 	}
	// }
	// for(int i=1;i<=n;i++) {
	// 	if(temp[i]==0) {
	// 		ans[1] = i;
	// 		break;
	// 	}
	// }
	// int x , y;
 //    int expProd = 1 , prod = 1;
 //    for(int i=1;i<=n;i++) {
 //        expProd *= i;
 //    }
 //    for(int i=0;i<n;i++) {
 //        prod *= arr[i];
 //    }
 //    int expSum = 0 , sum = 0;
 //    expSum = n*(n+1)/2;
 //    for(int i=0;i<n;i++) {
 //        sum += arr[i];
 //    }
 //    y = (prod*(expSum-sum)) / (prod - expProd);
 //    ans[0] = abs(y);
 //    x = (expProd * y) / prod;
 //    ans[1] = abs(x);
	int *temp = (int *)malloc(sizeof(int) * (n+1));
	int i;
	/*for(i=0;i<=n;i++) temp[i] = 0;
	for (i = 1; i <= n; ++i)
		temp[arr[i-1]]++;
	for (i = 1; i <= n; ++i)
	{
		if(temp[i] > 1)
			ans[0] = i;
		else if(temp[i] == 0)
			ans[1] = i;
	}*/
	// int acS = 0 , sum = 0;
	// sum = (n*(n+1))/2;
	// for(i=0;i<n;i++) {
	// 	acS += arr[i];
	// }
	// int acS2 = 0 , sum2 = 0;
	// sum2 = (n*(n+1)*((2*n) + 1)) / 6;
	// for(i=0;i<n;i++) {
	// 	acS2 += (arr[i] * arr[i]);
	// }

	// int aminusb = acS - sum;
	// int aplusb = (acS2 - sum2) / (aminusb);
	// ans[0] = (aminusb+aplusb)/2;
	// ans[1] = -aminusb + ans[0];
	// return ans;
}

int main()
{
	int *ans = (int *)malloc(sizeof(int) * 2);
	// int n = 5;
	int n = 2;
	int *arr = (int *)malloc(sizeof(int) * n);
	// arr[0] = 3;
	// arr[1] = 1;
	// arr[2] = 2;
	// arr[3] = 3;
	// arr[4] = 5;
	arr[0] = 2 ;arr[1] = 2;
	ans = getRes(arr,n);
	printf("%d\n%d\n",ans[0],ans[1]);
	return 0;
}