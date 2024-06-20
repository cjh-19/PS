#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, x, y;
	cin >> T;
	vector<vector<int>>arr;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		vector<int>arr2;
		arr.push_back(arr2);
		arr[i].push_back(x);
		arr[i].push_back(y);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 2; j++)
			cout << arr[i][j] << " ";
		cout << "\n";
	}
	return 0;
}