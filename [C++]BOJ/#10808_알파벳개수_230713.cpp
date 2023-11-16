#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	int arr[26] = { 0, };
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		arr[str[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n";

	return 0;
}