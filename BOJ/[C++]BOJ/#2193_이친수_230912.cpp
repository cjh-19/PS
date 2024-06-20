#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long N;
	cin >> N;
	vector<long long> dp;
	dp.push_back(0);
	dp.push_back(1);
	for (int i = 2; i <= N; i++) {
		dp.push_back(dp[i - 1] + dp[i - 2]);
	}
	cout << dp[N] << "\n";

	return 0;
}