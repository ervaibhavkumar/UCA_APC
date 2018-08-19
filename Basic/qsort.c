#include <stdio.h>
#include <stdlib.h>

int comp1(void *x , void *y) 
{
	return *((int *)x) - *((int *)y);
}

int comp2(void *x , void *y) 
{
	return *((int *)y) - *((int *)x);
}

int main()
{
	int arr[] = {5 , 2 , 4 , 78 , 1 , 3};
	//for sorting in ascending order
	qsort(arr , 6 , sizeof(int) , comp1);
	//for sorting in descending order
	qsort(arr , 6 , sizeof(int) , comp2);

	for (int i = 0; i < 6; ++i)
	{
		printf("%d\n",*(arr+i));
	}
	return 0;
}