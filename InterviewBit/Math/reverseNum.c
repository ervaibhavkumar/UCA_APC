#include <stdio.h>

int getReverse(int n) {
	int rev = 0 , prev_rev = 0;
	while(n) {
		int curr = n % 10;
		rev = (rev*10) + curr;

		if((rev - curr)/10 != prev_rev) {
			return 0;
		}
		prev_rev = rev;
		n /= 10;
	}
	return rev;
}

int main()
{
	int n = 123;
	printf("%d\n",getReverse(n));
	return 0;
}