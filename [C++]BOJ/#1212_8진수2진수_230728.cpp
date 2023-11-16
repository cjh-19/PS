#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str, result;
	cin >> str;
	int  ch = str[0] - '0';
	if (str == "0") {
		cout << str;
		return 0;
	}
	if (ch / 4 == 1) {
		result.push_back('1');
		ch -= 4;
		result.push_back(ch / 2 + '0');
		if (ch / 2 == 1)
			ch -= 2;
		result.push_back(ch / 1 + '0');
	}
	else if (ch / 2 == 1) {
		result.push_back(ch / 2 + '0');
		if (ch / 2 == 1)
			ch -= 2;
		result.push_back(ch / 1 + '0');
	}
	else {
		result.push_back(ch / 1 + '0');
	}
	for (int i = 1; i < str.length(); i++) {
		ch = str[i] - '0';
		for (int j = 4; j >= 1; j /= 2) {
			result.push_back(ch / j + '0');
			if (ch / j == 1)
				ch -= j;
		}
	}

	cout << result << "\n";
	return 0;
}