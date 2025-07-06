#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int N, B;
int minDiff = INT_MAX;

int H[10001];

void dfs(int idx, int height) {
	if (height >= B) {
		minDiff = min(minDiff, height - B);
		return;
	}

	if (height - B >= minDiff || idx == N) return;

	dfs(idx + 1, height + H[idx]);
	dfs(idx + 1, height);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		minDiff = INT_MAX;
		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> H[i];
		}

		dfs(0, 0);

		cout << "#" << t << " " << minDiff << "\n";
	}

	return 0;
}