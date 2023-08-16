#include<iostream>

using namespace std;

#define MAX 1000001
int dp[MAX] = { 0, };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Num;
	cin >> Num;
	for (int i = 2; i <= Num; i++) {
		if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = min(dp[i / 3], dp[i / 2]) + 1;
		}
		else if (i % 3 == 0)
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		else if (i % 2 == 0)
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}
	cout << dp[Num] << "\n";

	return 0;
}