#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	string str;
	cin >> str;
	vector<int>num;
	for (int i = 0; i < str.length(); i++) {
		num.push_back(str[i] - '0');
	}
	sort(num.begin(), num.end());
	for (int i = num.size() - 1; i >= 0; i--)
		cout << num[i];

	return 0;
}