#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Num;
	cin >> Num;
	vector<int> card;
	for (int i = 0; i < Num; i++) {
		int n;
		cin >> n;
		card.push_back(n);
	}
	vector<int> dp;
	dp.push_back(0);
	int max = 0;
	for (int i = 1; i <= Num; i++) {
		dp.push_back(0);
		for (int j = 0; j < i; j++) {
			if (max < card[j] + dp[i - j - 1]) {
				max = card[j] + dp[i - j - 1];
				dp[i] = max;
			}
		}
	}
	cout << dp[Num] << "\n";

	return 0;
}