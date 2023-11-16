#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	string arr[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	int count = 0;
	for (int i = 0; i < str.length(); i++) {
		int N = 0;
		for (int j = 0; j < 8; j++) {
			string newstr = str.substr(i, arr[j].length());
			if (newstr == arr[j]) {
				count++;
				i += arr[j].length() - 1;
				N = 1;
				break;
			}
		}
		if (N == 0)
			count++;
	}
	cout << count;
	return 0;
}