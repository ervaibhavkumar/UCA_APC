#include <stdio.h>
#include <stdlib.h>

int max(int a , int b) {
	if(a>b) return a;
	return b;
}

int steps(int *a , int n1 , int *b , int n2) {
	int steps = 0;
	for(int i=0;i<n1-1;i++) {
		steps += max(abs(a[i] - a[i+1]),abs(b[i] - b[i+1]))
	}
	return steps;
}

int main()
{
	printf("%d\n",steps(a,n1,b,n2));
	return 0;
}