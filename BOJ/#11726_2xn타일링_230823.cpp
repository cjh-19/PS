#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int num;
	cin >> num;
	vector<int> dp;
	dp.push_back(1);
	dp.push_back(2);
	for (int i = 2; i < num; i++) {
		dp.push_back((dp[i - 1] + dp[i - 2]) % 10007);
	}
	cout << dp[num - 1] << "\n";

	return 0;
}