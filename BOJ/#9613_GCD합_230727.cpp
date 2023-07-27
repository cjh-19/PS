#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int x, int y) {
	while (y % x != 0) {
		int temp = y;
		y = x;
		x = temp % x;
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Num;
	cin >> Num;
	for (int i = 0; i < Num; i++) {
		vector<int> vt;
		long long sum = 0;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			vt.push_back(tmp);
		}
		sort(vt.begin(), vt.end());
		for (int j = 0; j < vt.size() - 1; j++) {
			for (int k = j + 1; k < vt.size(); k++) {
				sum += gcd(vt[j], vt[k]);
			}
		}
		cout << sum << "\n";
	}

	return 0;
}