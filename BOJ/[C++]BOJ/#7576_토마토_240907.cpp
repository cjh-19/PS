#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int M, N;
int map[1000][1000]; // N x M
int minDay = 0;

struct Point {
	int x, y, day; // 위치, 날짜
};
queue<Point> Q;

void bfs() {
	while (!Q.empty()) {
		Point p = Q.front();
		int x = p.x;
		int y = p.y;
		int day = p.day;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0) {
				map[nx][ny] = 1;
				Q.push({ nx, ny, day + 1 });
				minDay = day + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> M >> N;
	int startstat = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int stat;
			cin >> stat;
			map[i][j] = stat;
			if (stat == 0) startstat = 1;
			else if (stat == 1) Q.push({ i,j,0 });
		}
	}
	// 익지 않은 토마토가 입력되지 않은 경우
	if (startstat == 0) {
		cout << 0 << "\n";
		return 0;
	}

	bfs();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}
		}
	}

	cout << minDay << "\n";

	return 0;
}