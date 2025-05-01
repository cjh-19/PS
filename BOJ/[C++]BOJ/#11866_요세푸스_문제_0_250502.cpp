#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	int cnt = 0;
	cout << "<";
	while (!q.empty()) {
		cnt++;
		int n = q.front();
		q.pop();
		if (cnt == K) {
			if (q.empty()) cout << n << ">";
			else cout << n << ", ";
			cnt = 0;
		}
		else q.push(n);
	}

	return 0;
}