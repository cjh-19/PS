#include <iostream>
#include <string>

using namespace std;

int problem, N, k;
char xyz;

pair<long long, string> stringLen(int N) {
	pair<long long, string> dp[101];
	dp[1] = { 1, "X" };
	dp[2] = { 2, "YZ" };
	dp[3] = { 2, "ZX" };

	for (int i = 4; i <= N; i++) {
		dp[i] = { dp[i - 2].first + dp[i - 3].first, dp[i - 3].second + dp[i - 2].second };
	}
	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> problem >> N;
	pair<long long, string> result;
	result = stringLen(N);
	if (problem == 1) {
		cout << result.first;
	}
	else if (problem == 2) {
		cin >> k;
		cout << result.second[k - 1];
	}
	else if (problem == 3) {
		cin >> xyz;
		long long cnt = 0;
		string str = result.second;
		for (long long i = 0; i < str.length(); i++) {
			if (str[i] == xyz) cnt++;
		}
		cout << cnt;
	}

	return 0;
}