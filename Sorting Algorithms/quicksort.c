#include <stdio.h>
#include <stdlib.h>

void swap(int *a , int i , int j) {
	//eliminate redundant checks
	if(i==j) return;
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void qsort(int *a, int l , int r) {
	if(l>=r) return;
	int ra = rand() % r + l;
	// printf("%d\n",ra );
	swap(a,ra,l);
	int last = l;
	for(int i=l+1;i<=r;i++) {
		if(a[i] < a[l]) {
			swap(a,i,++last);
		}
	}
	swap(a,l,last);
	qsort(a,l,last-1);
	qsort(a,last+1,r);
}

int main()
{
	int a[] = {4,2,74,9,13};
	int n = 5;
	qsort(a,0,n-1);
	for(int i=0;i<n;i++) {
		printf("%d\n",a[i]);
	}
	return 0;
}