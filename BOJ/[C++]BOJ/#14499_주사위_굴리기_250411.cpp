#include <bits/stdc++.h>

using namespace std;

int N, M, x, y, K;

int board[20][20];
int dice[6]; // 주사위 상태 { 상, 하, 좌, 우, 앞, 뒤 }

void rotation(int k) {
	// 회전하면 주사위 또는 보드에 값을 넣고
	// 주사위의 현재 위치 변경

	int dicetmp[6];
	for (int i = 0; i < 6; i++) {
		dicetmp[i] = dice[i];
	}

	if (k == 1) { // 동
		// 보드를 벗어나면 패스
		if (y + 1 >= M) return;

		// 동쪽 회전
		// 0 -> 3 / 1 -> 2 / 2 -> 0 / 3 -> 1
		dice[3] = dicetmp[0];
		dice[2] = dicetmp[1];
		dice[0] = dicetmp[2];
		dice[1] = dicetmp[3];


		y += 1;
		// 보드판이 0이면 보드에 주사위 값 넣기
		if (board[x][y] == 0) {
			board[x][y] = dice[1];
		}
		else {
			dice[1] = board[x][y];
			board[x][y] = 0;
		}
	}
	else if (k == 2) { // 서
		if (y - 1 < 0) return;

		// 서쪽 회전
		// 0 -> 2 / 1 -> 3 / 2 -> 1 / 3 -> 0
		dice[2] = dicetmp[0];
		dice[3] = dicetmp[1];
		dice[1] = dicetmp[2];
		dice[0] = dicetmp[3];

		y -= 1;
		// 보드판이 0이면 보드에 주사위 값 넣기
		if (board[x][y] == 0) {
			board[x][y] = dice[1];
		}
		else {
			dice[1] = board[x][y];
			board[x][y] = 0;
		}
	}
	else if (k == 3) { // 북
		if (x - 1 < 0) return;

		// 북쪽 회전
		// 0 -> 5 / 1 -> 4 / 4 -> 0 / 5 -> 1
		dice[5] = dicetmp[0];
		dice[4] = dicetmp[1];
		dice[0] = dicetmp[4];
		dice[1] = dicetmp[5];


		x -= 1;
		// 보드판이 0이면 보드에 주사위 값 넣기
		if (board[x][y] == 0) {
			board[x][y] = dice[1];
		}
		else {
			dice[1] = board[x][y];
			board[x][y] = 0;
		}
	}
	else if (k == 4) { // 남
		if (x + 1 >= N) return;

		// 남쪽 회전
		// 0 -> 4 / 1 -> 5 / 4 -> 1 / 5 -> 0
		dice[4] = dicetmp[0];
		dice[5] = dicetmp[1];
		dice[1] = dicetmp[4];
		dice[0] = dicetmp[5];


		x += 1;
		// 보드판이 0이면 보드에 주사위 값 넣기
		if (board[x][y] == 0) {
			board[x][y] = dice[1];
		}
		else {
			dice[1] = board[x][y];
			board[x][y] = 0;
		}
	}

	cout << dice[0] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> x >> y >> K;

	// 보드 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	// 명령어 입력
	for (int i = 0; i < K; i++) {
		int k;
		cin >> k;
		// 주사위 회전 하며 상단 값 출력
		rotation(k);
	}

	return 0;
}