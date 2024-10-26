#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 문자열 덧셈
string add(string a, string b) {
	string result = "";

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int pos = 1; // 현재 자리수
	int maxlen = max(a.length(), b.length());
	int next = 0;
	while (pos <= maxlen) {
		int x = 0, y = 0;
		if (pos <= a.length()) {
			x = a[pos - 1] - '0';
		}
		if (pos <= b.length()) {
			y = b[pos - 1] - '0';
		}

		result += (next + x + y) % 10 + '0';

		if (x + y + next >= 10) { // 올림수
			next = 1;
		}
		else {
			next = 0;
		}
		pos++;
	}
	if (next > 0) {
		result += next + '0';
	}
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string dp[251];
	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";
	dp[3] = add(dp[2], add(dp[1], dp[1]));
	// dp[n] = dp[n-1] + dp[n-2] + dp[n-2]

	for (int i = 4; i <= 250; i++) {
		dp[i] = add(dp[i - 1], add(dp[i - 2], dp[i - 2]));
	}

	int n;

	while (cin >> n) {
		cout << dp[n] << "\n";
	}

	return 0;
}