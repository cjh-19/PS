#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M; // 격자 크기, 분사 세기
int board[16][16];

// 상 하 좌 우 / 좌상 대각선부터 시계 => 8개 방향
int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, 1, -1 };

// 1. 상하좌우로 먼저 탐색
// 2. 대각선으로 탐색
// 이때 정해진 방향으로만 쭉 가야함 (방향 고정)
int bfs(int x, int y) {
	// x좌표 y좌표 방향 진행거리
	queue<tuple<int, int, int, int>> q;

	// 1. 상하좌우
	int plusSum = board[x][y];
	for (int i = 0; i < 4; i++) {
		q.push({ x, y, i, 1 });
	}

	while (!q.empty()) {
		int xpos = get<0>(q.front());
		int ypos = get<1>(q.front());
		int dir = get<2>(q.front());
		int dis = get<3>(q.front());

		q.pop();

		int nx = xpos + dx[dir];
		int ny = ypos + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || dis >= M) continue;

		q.push({ nx, ny, dir, dis + 1 });
		plusSum += board[nx][ny];
	}

	// 2. 대각선
	int xSum = board[x][y];
	for (int i = 4; i < 8; i++) {
		q.push({ x, y, i, 1 });
	}

	while (!q.empty()) {
		int xpos = get<0>(q.front());
		int ypos = get<1>(q.front());
		int dir = get<2>(q.front());
		int dis = get<3>(q.front());

		q.pop();

		int nx = xpos + dx[dir];
		int ny = ypos + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N || dis >= M) continue;

		q.push({ nx, ny, dir, dis + 1 });
		xSum += board[nx][ny];
	}

	return max(plusSum, xSum);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int sum = 0;

		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sum = max(sum, bfs(i, j));
			}
		}

		cout << "#" << t << " " << sum << "\n";
	}


	return 0;
}