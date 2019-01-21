#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int findRedundant(string str) {
	stack<char> s;
	for(int i=0;i<str.length();i++) {
		if(str[i]==')') {
			char top = s.top();
			s.pop();
			int flag = 1;
			while(top!= '(') {
				if(top=='+' || top=='-' || top=='*' || top=='/') {
					flag = 0;
				}
				top = s.top();
				s.pop();
			}
			if(flag) return 1;
		}
		else s.push(str[i]);
	}
	return 0;
}

int main()
{
	string str = "(a+b)"; 
    printf("%d\n",findRedundant(str));

	return 0;
}