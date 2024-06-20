#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		char ch = str[i];
		if (str[i] >= 'A' && str[i] <= 'Z') {
			if (ch + 13 <= 'Z')
				ch = ch + 13;
			else if (ch + 13 > 'Z')
				ch = ch - 13;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			if (ch + 13 <= 'z')
				ch = ch + 13;
			else if (ch + 13 > 'z')
				ch = ch - 13;
		}
		str[i] = ch;
	}
	for (int i = 0; i < str.length(); i++) {
		cout << str[i];
	}
	cout << "\n";

	return 0;
}