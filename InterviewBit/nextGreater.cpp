#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
	int arr[] = {4,5,2,25};
	int n = 4;
	stack<int> stk;

	stk.push(arr[0]);

	for(int i=1;i<n;i++) {

		if (stk.empty()) {
	      stk.push(arr[i]);
	      continue;
	    }

		while(stk.empty()==false && arr[i] > stk.top()) {
			cout<<stk.top()<<"->"<<arr[i]<<endl;
			stk.pop();
		}
		stk.push(arr[i]);
	}
	while(!stk.empty()) {
		cout<<stk.top()<<"->-1\n";
		stk.pop();
	}
	return 0;
}