#include <stdio.h>
#include <stdlib.h>

int numOnes(int n) {
	return __builtin_popcount(n);
}

int main()
{
	int n = 3;
	printf("%d\n",numOnes(n));
	return 0;
}