#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPalindrome(int n) {
	if(n<0) return 0;
    int divisor = 1; 

    while (n / divisor >= 10) 
        divisor *= 10; 

    while (n != 0) 
    { 
        int leading = n / divisor; 
        int trailing = n % 10; 

        if (leading != trailing) 
            return 0; 

        n = (n % divisor) / 10; 


        divisor = divisor / 100; 
    } 
    return 1; 
}

int main()
{
	int n = 13221;
	printf("%d\n",isPalindrome(n));
	return 0;
}