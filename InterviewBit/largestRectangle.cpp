#include <iostream>
#include <stack>

using namespace std;

int maxArea(int *arr , int n) {
	int max = -1 , area_top;
	int i = 0 ,tp;
	stack<int> s;

	while(i<n) {
		if(s.empty() || arr[i]>=arr[s.top()]) {
			s.push(i);
			i++;
		}
		else {
			tp = s.top();
			s.pop();

			if(s.empty()) {
				area_top = arr[tp] * i;
			}
			else {
				area_top = arr[tp] * (i-s.top()-1);
			}

			if(max<area_top) {
				max = area_top;
			}
		}
	}
	while(!s.empty()) {
		tp = s.top();
		s.pop();

		if(s.empty()) {
			area_top = arr[tp] * i;
		}
		else {
			area_top = arr[tp] * (i-s.top()-1);
		}

		if(max<area_top) {
			max = area_top;
		}
	}
	return max;
}

int main()
{
	int arr[] = {2,1,2,3,1};
	int n = 5;

	cout<<maxArea(arr,n)<<endl;
	return 0;
}