#include <iostream>
#include <cmath>

using namespace std;

int N;
int map[15]; // 각 행의 퀸의 위치 저장
int cnt = 0; // 경우의 수

bool isqueen(int lowcnt) { // lowcnt : 현재 행 위치
	for (int i = 0; i < lowcnt; i++) {
		// 같은 열인지, 대각선인지(아래 대각선은 안채워졌으므로 판단 안함)
		if (map[lowcnt] == map[i] || lowcnt - i == abs(map[lowcnt] - map[i])) {
			return false;
		}
	}
	return true;
}

void dfs(int lowcnt) {
	// N-1까지 다 채워졌다면 경우의 수 증가
	if (lowcnt == N) {
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		map[lowcnt] = i;
		if (isqueen(lowcnt)) { // lowcnt 행, i 열
			dfs(lowcnt + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	dfs(0);

	cout << cnt;

	return 0;
}