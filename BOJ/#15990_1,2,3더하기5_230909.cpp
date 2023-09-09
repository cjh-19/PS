#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		vector<long long> dp;
		dp.push_back(1);
		dp.push_back(1);
		dp.push_back(3);
		dp.push_back(3);
		dp.push_back(5);
		for (int j = 5; j < num; j++) {
			dp.push_back((dp[j - 1] + dp[j - 2] + dp[j - 3] - 3) % 1000000009);
		}
		cout << dp[num - 1] << "\n";
	}

	return 0;
}