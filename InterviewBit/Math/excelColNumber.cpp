#include <iostream>
#include <cstdio>

using namespace std;

int getColNum(string s) {
	int count = 0;
	for(int i=0;i<s.length();i++) {
		count *= 26;
		count += s[i] - 'A' + 1;
	}
	return count;
}

int main()
{
	string s = "AB";
	printf("%d\n",getColNum(s));
	return 0;
}