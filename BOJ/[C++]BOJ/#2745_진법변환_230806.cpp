#include<iostream>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	int num;
	cin >> str >> num;
	int result = 0;
	for (int i = 0; i < str.length(); i++) {
		int tmp;
		if (str[i] >= 'A' && str[i] <= 'Z') {
			tmp = str[i] - 'A' + 10;
		}
		else
			tmp = str[i] - '0';
		result += tmp * pow(num, str.length() - i - 1);
	}
	cout << result << "\n";

	return 0;
}