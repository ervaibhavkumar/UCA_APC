#include <stdio.h>

void func1(int x , int y , int (*a)[x][y]) {
	for(int i=0;i<x;i++) {
		for(int j=0;j<y;j++) {
			printf("%d\t" , *(*(*a+i)+j) );
		}
		printf("\n");
	}
}

void func2(int x , int y , int (*a)[y]) {
	for(int i=0;i<x;i++) {
		for(int j=0;j<y;j++) {
			printf("%d\t" , *(*(a+i)+j) );
		}
		printf("\n");
	}
}

void func3(int x , int y , int (*a)) {
	for(int i=0;i<x*y;i++) {
		printf("%d\t", *(a+i));
		if (i%3==2) printf("\n");
	}
}

int main()
{
	int arr[3][3] = {1,2,3,4,5,6,7,8,9};
	func1(3,3,&arr); //Whole array is sent
	func2(3,3,arr);  //first row is sent
	func3(3,3,*arr); //first element is sent
	return 0;
}