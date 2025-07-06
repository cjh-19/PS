#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int board[301][301]; // 빈칸 0, 지뢰 1
bool visited[301][301];

int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

bool checkBomb(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (board[nx][ny] == 1) return true;
	}

	return false;
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;

	while (!q.empty()) {
		int xpos = q.front().first;
		int ypos = q.front().second;

		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = xpos + dx[i];
			int ny = ypos + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || board[nx][ny] == 1) continue;
			visited[nx][ny] = true;
			if (!checkBomb(nx, ny)) {
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int openCnt = 0;

		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				char c;
				cin >> c;
				if (c == '.') board[i][j] = 0; // 빈칸
				else board[i][j] = 1; // 지뢰
			}
		}
		memset(visited, false, sizeof(visited));

		// 모든 지점을 돌며 주변 8칸이 빈칸이라면 bfs 시작
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!checkBomb(i, j) && !visited[i][j] && board[i][j] == 0) {
					bfs(i, j);
					openCnt++;
				}
			}
		}

		// 단일 칸 모두 찍기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] == 0 && !visited[i][j]) {
					openCnt++;
				}
			}
		}

		cout << "#" << t << " " << openCnt << "\n";
	}

	return 0;
}