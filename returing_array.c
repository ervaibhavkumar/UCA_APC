#include <stdio.h>

int* func1(int *x) {
	//need to make it static
	static int arr[] = {2 , 4, 88 , 5 , 7};
	*x = 5;
	return arr;
}

int (*func2(int *x))[5] {
	static int arr1[] = {2 , 4, 88 , 5 , 7};
	*x = 5;
	return &arr1;
}

int main()
{
	int n;
	int *a = func1(&n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",*(a+i));
	}
	int (*b)[5] = func2(&n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",*(*b+i));
	}
	return 0;
}