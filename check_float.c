#include <stdio.h>

int main()
{
	float x = 5.3f;
	unsigned char *ch = (char *)(&x);
	for(int i=0;i<4;i++) {
		printf("%d ",*(ch+i));
	}
	return 0;
}