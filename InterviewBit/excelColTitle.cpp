#include <iostream>
#include <string>

using namespace  std;

string getColTitle(int n) {
	string s = "";
	while(n) {
		int tmp = n%26;
		if(tmp==0) {
			char chr = 'Z';
			s += chr;
			n = (n/26) - 1;
		}
		else {
			char chr = 'A' + tmp - 1;
			s += chr;
			n /= 26;
		}
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	int n = 27;
	cout<<getColTitle(n)<<endl;
	return 0;
}