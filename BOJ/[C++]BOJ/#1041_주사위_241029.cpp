#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n;
	vector<int> num(6);
	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> num[i];
	}
	vector<long long> minnum;
	minnum.push_back(min(num[0], num[5]));
	minnum.push_back(min(num[1], num[4]));
	minnum.push_back(min(num[2], num[3]));
	sort(minnum.begin(), minnum.end());

	long long result = 0;

	// 주사위가 1개인 경우
	if (n == 1) {
		sort(num.begin(), num.end());
		cout << num[0] + num[1] + num[2] + num[3] + num[4];
		return 0;
	}
	// 3면
	result += 4 * (minnum[0] + minnum[1] + minnum[2]);

	// 2면
	result += (8 * n - 12) * (minnum[0] + minnum[1]);

	// 1면
	result += (5 * n * n - 16 * n + 12) * minnum[0];

	cout << result;

	return 0;
}