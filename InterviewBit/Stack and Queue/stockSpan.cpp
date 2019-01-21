#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	int arr[] = {10, 4, 5, 90, 120, 80};
	int n = 6;

	int *s = (int *)malloc(sizeof(int) * n);

	stack<int> stk;
	stk.push(0);
	s[0] = 1;

	for(int i=1;i<n;i++) {
		while(!stk.empty() && arr[stk.top()] <= arr[i]) {
			stk.pop();
		}
		if(stk.empty()) {
			s[i] = i+1;
		}
		else {
			s[i] = i - stk.top();
		}
		stk.push(i);
	}

	for(int i=0;i<n;i++) {
		printf("%d\n",s[i]);
	}
	return 0;
}