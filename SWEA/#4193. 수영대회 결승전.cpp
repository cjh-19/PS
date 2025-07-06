#include <iostream>
#include <queue>
#include <tuple>
#include <limits.h>

using namespace std;

int N;

int board[16][16];
pair<int, int> startPoint;
pair<int, int> endPoint;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int dijkstra(int x, int y) {
	int dist[16][16];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INT_MAX;
		}
	}

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	pq.push({ 0, x, y });
	dist[x][y] = 0;

	bool finishChk = false;
	while (!pq.empty()) {
		int curtime = get<0>(pq.top());
		int xpos = get<1>(pq.top());
		int ypos = get<2>(pq.top());

		pq.pop();

		if (curtime > dist[xpos][ypos]) continue;

		if (xpos == endPoint.first && ypos == endPoint.second) {
			return curtime;
		}

		for (int i = 0; i < 4; i++) {
			int nx = xpos + dx[i];
			int ny = ypos + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] == 1) continue;

			int weight;
			if (board[nx][ny] == 2) {
				weight = 3 - curtime % 3;
			}
			else {
				weight = 1;
			}

			if (dist[nx][ny] > weight + curtime) {
				dist[nx][ny] = weight + curtime;
				pq.push({ weight + curtime, nx, ny });
			}
		}
	}

	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}
		int x, y;
		cin >> x >> y;
		startPoint = { x, y };
		cin >> x >> y;
		endPoint = { x, y };

		cout << "#" << t << " " << dijkstra(startPoint.first, startPoint.second) << "\n";
	}

	return 0;
}