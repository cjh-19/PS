#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int cnt = 0, rgcnt = 0;

int board[101][101]; // R:0, G:1, B:2
bool visited[101][101];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isAllVisited() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) return false;
		}
	}
	return true;
}

void bfs() {
	queue<pair<int, int>> q;
	int nowColor;

	bool chk = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				q.push({ i, j });
				nowColor = board[i][j];
				visited[i][j] = true;
				chk = true;
				break;
			}
		}
		if (chk) break;
	}

	while (!q.empty()) {
		int xpos = q.front().first;
		int ypos = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xpos + dx[i];
			int ny = ypos + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny] != nowColor || visited[nx][ny]) continue;

			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
}

void rgbfs() {
	queue<pair<int, int>> q;
	int nowColor;

	bool chk = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				q.push({ i, j });
				nowColor = board[i][j];
				visited[i][j] = true;
				chk = true;
				break;
			}
		}
		if (chk) break;
	}

	while (!q.empty()) {
		int xpos = q.front().first;
		int ypos = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xpos + dx[i];
			int ny = ypos + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;

			if ((nowColor == 0 || nowColor == 1) && (board[nx][ny] == 0 || board[nx][ny] == 1)) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
			else if (board[nx][ny] == nowColor) {
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str[j] == 'R') {
				board[i][j] = 0;
			}
			else if (str[j] == 'G') {
				board[i][j] = 1;
			}
			else if (str[j] == 'B') {
				board[i][j] = 2;
			}
		}
	}

	while (!isAllVisited()) {
		bfs();
		cnt++;
	}

	memset(visited, false, sizeof(visited));

	while (!isAllVisited()) {
		rgbfs();
		rgcnt++;
	}

	cout << cnt << " " << rgcnt;

	return 0;
}