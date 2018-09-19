#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int trap(int *arr , int n) {
	int val = 0 , highest ,i;
	if(arr[1] < arr[0]) {
		val += arr[0] - arr[1];
		highest = arr[0];
		i = 2;
	}
	else {
		highest = arr[1];
		i = 2;
	}
	for(;i<n-1;i++) {
		if(arr[i] < highest) {
			val += highest - arr[i];
		}
		else {
			highest = arr[i];
		}
	}
	return val;
}

int main()
{
	int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int n = 12;
	// int arr[] = {3, 0, 0, 2, 0, 4};
	// int n = 6;
	int water = trap(arr,n);
	cout<<water<<endl;
	return 0;
}