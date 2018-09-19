#include <iostream>
#include <vector>

using namespace std;

vector<int> getRes(vector<int> arr) {
	bool temp[arr.size() + 1];
	int repeat , missing;
	for(int i=0;i<arr.size();i++) {
		if(temp[arr[i]] == true) {
			repeat = arr[i];
		}
		else {
			temp[arr[i]] = true;
		}
	}
	for(int i=1;i<arr.size()+1;i++) {
		if(temp[i] == false) {
			missing = i;
			break;
		}
	}
	vector<int> res(2);
	res.push_back(repeat);
	res.push_back(missing);
	return res;
}

int main()
{
	vector<int> v,ans;
	// arr[0] = 3;
	// arr[1] = 1;
	// arr[2] = 2;
	// arr[3] = 3;
	// arr[4] = 5;
	v[0] = 2;
	v[1] = 2;
	ans = getRes(v);
	cout<<ans[0]<<endl<<ans[1]<<endl;
	return 0;
}