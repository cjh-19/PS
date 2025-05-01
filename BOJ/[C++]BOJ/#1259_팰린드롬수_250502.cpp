#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (1) {
		string n;
		cin >> n;
		if (n == "0") break;

		bool check = false;
		for (int i = 0; i < n.size() / 2; i++) {
			if (n[i] != n[n.size() - 1 - i]) {
				cout << "no" << "\n";
				check = true;
				break;
			}
		}
		if (!check) cout << "yes" << "\n";
	}

	return 0;
}