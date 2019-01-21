#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

void deleteMid(stack<int> &s , int n , int curr=0) {
	if(s.empty() || curr==n) return;
	int x = s.top();
	s.pop();

	deleteMid(s,n,curr+1);

	if(curr!=n/2) {
		s.push(x);
	}
}

int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	deleteMid(s , s.size());

	while(!s.empty()) {
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}