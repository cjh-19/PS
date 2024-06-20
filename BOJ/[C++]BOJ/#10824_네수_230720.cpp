#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str[4];
	for (int i = 0; i < 4; i++) {
		cin >> str[i];
	}
	string s1, s2;
	s1 = str[0] + str[1];
	s2 = str[2] + str[3];
	cout << stoll(s1) + stoll(s2) << "\n";
	return 0;
}