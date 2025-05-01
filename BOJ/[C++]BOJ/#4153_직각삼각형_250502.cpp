#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		vector<int> t(3);
		cin >> t[0] >> t[1] >> t[2];
		if (t[0] == 0 && t[1] == 0 && t[2] == 0) break;

		sort(t.begin(), t.end());
		if (t[0] * t[0] + t[1] * t[1] == t[2] * t[2]) cout << "right" << "\n";
		else cout << "wrong" << "\n";
	}

	return 0;
}