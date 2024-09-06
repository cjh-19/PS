#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int T;
int M, N, K;

int map[50][50]; // M x N
queue<pair<int, int>> Q;

void bfs(int x, int y) {
	Q.push({ x, y });
	map[x][y] = 0;

	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && map[nx][ny] == 1) {
				Q.push({ nx, ny });
				map[nx][ny] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}
		int cnt = 0;
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (map[j][k] == 1) {
					bfs(j, k);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}