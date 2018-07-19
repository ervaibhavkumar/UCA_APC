#include <stdio.h>

int main()
{
	int a = 3 , b = 1 , c = 2;
	//using ternary operator
	int max = (a>b)?((a>c)?a:c):(b>c?b:c);
	printf("%d\n",max);
	return 0;
}