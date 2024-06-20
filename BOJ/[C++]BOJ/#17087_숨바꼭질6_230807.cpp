#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int x, int y) {
	if (x % y != 0)
		return gcd(y, x % y);
	return y;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Bro, Me, position;
	cin >> Bro >> Me;
	vector<int> vt;
	for (int i = 0; i < Bro; i++) {
		cin >> position;
		vt.push_back(abs(position - Me));
	}
	sort(vt.begin(), vt.end());
	if (vt.size() == 1)
		cout << vt[0] << "\n";
	else {
		int g_tmp = gcd(vt[0], vt[1]);
		for (int i = 2; i < vt.size(); i++) {
			g_tmp = gcd(g_tmp, vt[i]);
		}

		cout << g_tmp << "\n";
	}

	return 0;
}