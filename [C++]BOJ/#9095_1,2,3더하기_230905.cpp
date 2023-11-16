#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Num;
	cin >> Num;
	for (int i = 0; i < Num; i++) {
		vector<int> dp;
		dp.push_back(1);
		dp.push_back(2);
		dp.push_back(4);
		int N;
		cin >> N;
		for (int j = 3; j < N; j++) {
			dp.push_back(dp[j - 1] + dp[j - 2] + dp[j - 3]);
		}
		cout << dp[N - 1] << "\n";
	}
	
	return 0;
}