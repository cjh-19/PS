#include <bits/stdc++.h>

using namespace std;

int A, B;

void bfs() {
	queue<pair<long long, int>> q; // 시작 숫자, 횟수
	q.push({ A, 0 });

	while (!q.empty()) {
		long long curNum = q.front().first;
		int curCnt = q.front().second;
		q.pop();

		if (curNum == B) {
			cout << curCnt + 1;
			return;
		}

		if (curNum * 2 <= B) q.push({ curNum * 2, curCnt + 1 });
		if (curNum * 10 + 1 <= B) q.push({ curNum * 10 + 1 , curCnt + 1 });
	}

	cout << -1;
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B;

	bfs();

	return 0;
}