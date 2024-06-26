#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	vector<int> arr(N + 1);
	vector<int> dp;
	vector<int> st;

	dp.push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp.push_back(1);
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	int max_len = 0;
	for (int i = 0; i <= N; i++) {
		if (max_len < dp[i])
			max_len = dp[i];
	}
	cout << max_len << "\n";
	for (int i = N; i > 0; i--) {
		if (dp[i] == max_len) {
			st.push_back(arr[i]);
			max_len--;
		}
	}
	for (int i = st.size() - 1; i >= 0; i--) {
		cout << st[i] << " ";
	}

	return 0;
}

// 코드의 간소화가 필요할 듯