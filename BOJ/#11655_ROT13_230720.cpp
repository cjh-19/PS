#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	vector<char> rot;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int ch = str[i] + 13;
			if (ch > 'Z')
				ch = 'A' + (ch - 'Z') - 1;
			rot.push_back(ch);
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			int ch = str[i] + 13;
			if (ch > 'z')
				ch = 'a' + (ch - 'z') - 1;
			rot.push_back(ch);
		}
		else
			rot.push_back(str[i]);
	}
	for (int i = 0; i < rot.size(); i++) {
		cout << rot[i];
	}
	cout << "\n";

	return 0;
}