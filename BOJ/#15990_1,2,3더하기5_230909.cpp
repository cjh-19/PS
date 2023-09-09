#include<iostream>

using namespace std;

long long dp[100001][3] = { 0, };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		dp[0][0] = 1;
		dp[1][1] = 1;
		dp[2][0] = 1; dp[2][1] = 1; dp[2][2] = 1;
		for (int j = 3; j < num; j++) {
			dp[j][0] = dp[j - 1][1] + dp[j - 1][2];
			dp[j][1] = dp[j - 2][0] + dp[j - 2][2];
			dp[j][2] = dp[j - 3][0] + dp[j - 3][1];
		}
		cout << (dp[num - 1][0] + dp[num - 1][1] + dp[num - 1][2]) % 1000000009 << "\n";
	}

	return 0;
}