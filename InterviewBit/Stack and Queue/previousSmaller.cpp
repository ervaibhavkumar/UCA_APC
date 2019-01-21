#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int * findPreviousSmaller(int *arr , int n) {
	int *ans = (int *)malloc(sizeof(int) * n);

	ans[0] = -1;
	stack<int> stk;
	stk.push(arr[0]);

	for(int i=1;i<n;i++) {
		while(!stk.empty() && stk.top() >= arr[i]) {
			stk.pop();
		}
		if(stk.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = stk.top();
			// stk.pop();
		}
		stk.push(arr[i]);
	}
	return ans;
}

int main()
{
	// int arr[] = {4, 5, 2, 10, 8};
	// int n = 5;
	int arr[] = {1,2,3};
	int n = 3;
	int *ans = (int *)malloc(sizeof(int) * n);
	ans = findPreviousSmaller(arr,n);

	for(int i=0;i<n;i++) {
		cout<<ans[i]<<endl;
	}
	return 0;
}