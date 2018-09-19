#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int evaluate(string s) {
	stack<int> stk;
	int a,b;
	for(int i=0;i<s.length();i++) {
		if(s[i]>='0'&&s[i]<='9') {
			stk.push((int)s[i] - 48);
		}
		else if(s[i]=='+') {
			a = (int)stk.top();
			stk.pop();
			b = (int)stk.top();
			stk.pop();
			// printf("a=%d,b=%d\n",a,b);
			stk.push(a+b);
		}
		else if(s[i]=='-') {
			a = (int)stk.top();
			stk.pop();
			b = (int)stk.top();
			stk.pop();
			stk.push(b-a);
		}
		else if(s[i]=='*') {
			a = (int)stk.top();
			stk.pop();
			b = (int)stk.top();
			stk.pop();
			stk.push(a*b);
		}
		else if(s[i]=='/') {
			a = (int)stk.top();
			stk.pop();
			b = (int)stk.top();
			stk.pop();
			stk.push(b/a);
		}
	}
	return stk.top();
}

int main()
{
	// string s = "21+3*";
	string s = "495/*";
	int val = evaluate(s);
	printf("%d\n",val);
	return 0;
}