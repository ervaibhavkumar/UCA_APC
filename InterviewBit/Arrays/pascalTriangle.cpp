#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > pascal(int n) {
	vector<vector<int> > res;
	int i;
	for(i=0;i<n;i++) {
		if(i==0) {
			res[0].push_back(1);
		}
		else {
			for(int j=0;j<=i;j++) {
				if(j==0) {
					res[i].push_back(1);
				}
				else if(j==i) {
					res[i].push_back(res[i-1][j]);
				}
				else {
					res[i].push_back(res[i-1][j-1] + res[i-1][j]);
				}
			}
		}
	}
	return res;
}

int main()
{
	int n = 5;
	vector<vector<int> > res = pascal(n);
	// for(int i=0;i<res.size();i++) {
	// 	for(int j=0;j<res[i].size();j++) {
	// 		cout<<res[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	return 0;
}