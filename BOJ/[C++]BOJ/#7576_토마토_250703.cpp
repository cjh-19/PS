#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[6] = { -1, 1, 0 ,0, 0, 0 };
int dy[6] = { 0 ,0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int box[101][101][101];

int M, N, H;
int D = 0;

queue<pair<tuple<int, int, int>, int>> q;

void bfs() {
	while (!q.empty()) {
		int xpos = get<0>(q.front().first);
		int ypos = get<1>(q.front().first);
		int zpos = get<2>(q.front().first);
		int day = q.front().second;

		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx = xpos + dx[i];
			int ny = ypos + dy[i];
			int nz = zpos + dz[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H || box[nz][nx][ny] != 0) continue;

			q.push({ {nx, ny, nz }, day + 1 });
			box[nz][nx][ny] = 1;

			if (D < day + 1) D = day + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int n;
				cin >> n;
				if (n == 1) {
					q.push({ { j, k, i }, 0 });
				}
				box[i][j][k] = n;
			}
		}
	}
	bfs();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (box[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}

	cout << D << "\n";

	return 0;
}