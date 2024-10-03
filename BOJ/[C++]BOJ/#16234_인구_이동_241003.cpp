#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R; // 땅 크기, 인구차이 L<R
vector<vector<int>> map;
vector<vector<bool>> visited;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dayCnt = 0;

bool bfs(int x, int y) {
	bool check = false;
	int sum = map[x][y];
	queue<pair<int, int>> together;

	queue<pair<int, int>> Q;
	Q.push({ x, y });
	together.push({ x,y });
	visited[x][y] = true;

	while (!Q.empty()) {
		int xpos = Q.front().first;
		int ypos = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xpos + dx[i];
			int ny = ypos + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
				if (abs(map[xpos][ypos] - map[nx][ny]) >= L && abs(map[xpos][ypos] - map[nx][ny]) <= R) {
					check = true; // 연합이 생김
					visited[nx][ny] = true;
					Q.push({ nx, ny });
					together.push({ nx,ny });
					sum += map[nx][ny];
				}
			}
		}
	}
	int avg = sum / together.size();
	while (!together.empty()) {
		int xpos = together.front().first;
		int ypos = together.front().second;
		together.pop();
		map[xpos][ypos] = avg;
	}

	return check;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> L >> R;
	map.resize(N, vector<int>(N));
	visited.resize(N, vector<bool>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	bool check = true;
	while (check) {
		check = false;
		fill(visited.begin(), visited.end(), vector<bool>(N, false));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					if (bfs(i, j)) check = true;
				}
			}
		}
		if (check)
			dayCnt++;
	}

	cout << dayCnt;

	return 0;
}