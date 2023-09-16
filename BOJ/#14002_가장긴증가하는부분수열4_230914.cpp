#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	vector<int> arr, dp;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	dp.push_back(1);
	for (int i = 1; i < N; i++) {
		dp.push_back(0);
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j])
				dp[i] = dp[j];
		}
		dp[i]++;
	}

	return 0;
}