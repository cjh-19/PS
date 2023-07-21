#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	cin >> str;
	vector<string> vt;
	for (int i = 0; i < str.size(); i++) {
		string s;
		for (int j = i; j < str.size(); j++) {
			s += str[j];
		}
		vt.push_back(s);
	}
	sort(vt.begin(), vt.end());
	for (int i = 0; i < vt.size(); i++) {
		cout << vt[i] << "\n";
	}

	return 0;
}