#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	int dp[100][10] = { 0, };
	for (int i = 1; i < 10; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= 1000000000;
		}
	}
	int count = 0;
	for (int i = 0; i < 10; i++) {
		count = (count + dp[N - 1][i]) % 1000000000;
	}
	cout << count << "\n";

	return 0;
}