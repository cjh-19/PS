#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> money(n);
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}

	long long maxMoney = 0;
	long long sum = 0;
	for (int i = 0; i < m; i++) {
		sum += money[i];
	}
	maxMoney = max(maxMoney, sum);
	for (int start = 0; start < n - m; start++) {
		sum += money[start + m] - money[start];
		maxMoney = max(maxMoney, sum);
	}

	cout << maxMoney << "\n";

	return 0;
}