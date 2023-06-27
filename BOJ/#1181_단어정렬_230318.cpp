#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	vector<string>arr;
	string str;
	for (int i = 0; i < T;) {
		cin >> str;
		int count = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] == str){
				count = 1;
				T--;
			}
		}
		if (count == 0) {
			arr.push_back(str);
			i++;
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 1; i <= 50; i++) {
		for (int j = 0; j < T; j++) {
			if (arr[j].length() == i) {
				cout << arr[j] << "\n";
			}
		}
	}
	return 0;
}