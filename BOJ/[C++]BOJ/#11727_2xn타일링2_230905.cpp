#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Num;
	cin >> Num;
	vector<int> dp;
	dp.push_back(1);
	dp.push_back(3);
	for (int i = 2; i < Num; i++) {
		dp.push_back((dp[i - 1] + 2 * dp[i - 2]) % 10007);
	}
	cout << dp[Num - 1] << "\n";

	return 0;
}