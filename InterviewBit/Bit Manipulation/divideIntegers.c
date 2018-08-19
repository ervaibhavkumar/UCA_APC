#include <stdio.h>
#include <stdlib.h>

int divide(int dividend , int divisor) {
	long long quotient = 0 , temp = 0;
	int sign = ((dividend < 0) ^ (divisor<0)) ? -1 : 1;
	int i;
	dividend = abs(dividend);
	dividend = abs(divisor);
	for(i=30;i>=0;--i) {
		if(temp + (divisor<<i) <= dividend) {
			temp += (divisor<<i);
			quotient |= (1<<i);
		}
	}
	return sign * quotient;
}

int main()
{
	int dividend = 13 , divisor = 2;
	printf("%d\n",divide(dividend,divisor));
	return 0;
}