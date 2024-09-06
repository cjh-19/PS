#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N, M;
int map[101][101]; // N x M

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int visited[101][101];
int cnt[101][101];
queue < pair<int, int>> Q;

int bfs(int first, int second) {
	pair<int, int> p = { first, second };
	Q.push(p);
	visited[first][second] = true;
	cnt[first][second] = 1;

	while (!Q.empty()) {
		first = Q.front().first;
		second = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = first + dx[i];
			int ny = second + dy[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= M && !visited[nx][ny] && map[nx][ny] == 1) {
				Q.push({ nx, ny });
				visited[nx][ny] = true;
				cnt[nx][ny] = cnt[first][second] + 1;
			}
		}
	}
	return cnt[N][M];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string road;
		cin >> road;
		for (int j = 0; j < road.length(); j++) {
			map[i][j + 1] = road[j] - '0';
		}
	}

	cout << bfs(1, 1) << "\n";

	return 0;
}