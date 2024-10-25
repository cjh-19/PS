#include <iostream>
#include <string>

using namespace std;

long long dp[101];
long long cnt[101][3];

long long problem, N, k;
char xyz;

void stringLen(int N) {
	dp[1] = 1; // X
	dp[2] = 2; // YZ
	dp[3] = 2; // ZX
	cnt[1][0] = 1; // X
	cnt[2][1] = 1; // Y
	cnt[2][2] = 1; // Z
	cnt[3][0] = 1; // X
	cnt[3][2] = 1; // Z

	for (int i = 4; i <= N; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
		for (int j = 0; j < 3; j++) {
			cnt[i][j] = cnt[i - 3][j] + cnt[i - 2][j];
		}
	}
}

char chsearch() {
	string xyzstr[3] = { "X", "YZ", "ZX" };
	long long pos = k; // 현재 위치
	int index = N; // 현재 인덱스

	while (index > 3) {
		if (dp[index - 3] >= pos) { // 앞쪽에 있다면
			index -= 3;
		}
		else { // 뒤쪽에 있다면
			pos -= dp[index - 3];
			index -= 2;
		}
	}
	return xyzstr[index - 1][pos - 1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> problem >> N;
	stringLen(N);
	if (problem == 1) {
		cout << dp[N];
	}
	else if (problem == 2) {
		cin >> k;
		cout << chsearch();
	}
	else if (problem == 3) {
		cin >> xyz;
		if (xyz == 'X') {
			cout << cnt[N][0];
		}
		else if (xyz == 'Y') {
			cout << cnt[N][1];
		}
		else if (xyz == 'Z') {
			cout << cnt[N][2];
		}
	}

	return 0;
}