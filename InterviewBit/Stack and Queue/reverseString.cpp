#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main()
{
	string s = "abcd";
	stack<char>stk;

	for(int i=0;i<s.length();i++) {
		stk.push(s[i]);
	}
	while(!stk.empty()) {
		cout<<stk.top();
		stk.pop();
	}
	cout<<endl;
	return 0;
}