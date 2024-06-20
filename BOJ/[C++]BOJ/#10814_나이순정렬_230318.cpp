#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	vector<pair<int,string>>arr;
	int num;
	string str;
	for (int i = 0; i < T; i++) {
		cin >> num >> str;
		arr.push_back(make_pair(num,str));
	}
	for (int i = 1; i <= 200; i++) {
		for (int j = 0; j < T; j++) {
			if (arr[j].first == i)
				cout << arr[j].first << " " << arr[j].second << "\n";
		}
	}
	
	return 0;
}