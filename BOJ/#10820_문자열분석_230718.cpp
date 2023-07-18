#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	while (getline(cin, str)) {
		int count[4] = { 0, }; // 0 소문자, 1 대문자, 2 숫자, 3 공백
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'a' && str[i] <= 'z')
				count[0]++;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				count[1]++;
			else if (str[i] == ' ')
				count[3]++;
			else
				count[2]++;
		}
		for (int i = 0; i < 4; i++) {
			cout << count[i] << ' ';
		}
		cout << "\n";
	}

	return 0;
}