#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<int> arr;
	int num;
	cin >> num;
	while (num > 0) {
		string str;
		cin >> str;
		if (str == "push") {
			int N;
			cin >> N;
			arr.push_back(N);
		}
		else if (str == "pop") {
			if (arr.size() == 0)
				cout << -1 << "\n";
			else {
				cout << arr[arr.size() - 1] << "\n";
				arr.pop_back();
			}
		}
		else if (str == "size")
			cout << arr.size() << "\n";
		else if (str == "empty") {
			if (arr.size() == 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (str == "top") {
			if (arr.size() == 0)
				cout << -1 << "\n";
			else
				cout << arr[arr.size() - 1] << "\n";
		}

		num--;
	}
	
	return 0;
}