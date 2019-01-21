#include <stdio.h>
#include <stdlib.h>

int reverseBits(int n) {
	int res = 0,i,j=0;
	for(i=31;i>=0;i--) {
		int x = n & (1<<j);
		j++;
		if(x) res = res | (1<<i);
	}
	return res;
}

int main()
{
	int n = 3;
	printf("%d\n",reverseBits(n));
	return 0;
}