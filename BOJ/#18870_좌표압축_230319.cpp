#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	int n;
	vector<int>arr;
	vector<int>arr2;
	for (int i = 0; i < T; i++) {
		cin >> n;
		arr.push_back(n);
		arr2.push_back(n);
	}
	sort(arr2.begin(), arr2.end());
	arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
	
	for (int i = 0; i < T; i++) {
		cout << lower_bound(arr2.begin(), arr2.end(), arr[i]) - arr2.begin() << " ";
	}
	return 0;
}