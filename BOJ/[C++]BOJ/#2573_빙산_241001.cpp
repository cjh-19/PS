#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, cnt;
vector<vector<int>> map(300, vector<int>(300, 0));
int finish_time = -1; // 빙산 분리되는 시간

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// bfs로 체크
bool colapse() {
	bool visited[300][300] = { {false, } , };
	int coldCnt = 0;
	queue<pair<int, int>> Q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] != 0) {
				Q.push({ i,j });
				visited[i][j] = true;
				coldCnt++;
				break;
			}
		}
		if (!Q.empty()) break;
	}

	while (!Q.empty()) {
		pair<int, int> xy = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xy.first + dx[i];
			int ny = xy.second + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] != 0 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				coldCnt++;
				Q.push({ nx, ny });
			}
		}
	}

	if (coldCnt != cnt) return true;
	return false;
}

void melt() {
	vector<vector<int>> copymap(map);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int aroundCnt = 0;
			if (map[i][j] != 0) {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0) {
						aroundCnt++;
					}
				}
				copymap[i][j] = max(0, map[i][j] - aroundCnt);
			}
		}
	}
	map = copymap;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) cnt++;
		}
	}

	int current = 0;
	while (1) { // 빙산이 모두 녹을때까지 반복
		bool check = true;
		cnt = 0; // 빙산 개수 다시 세기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] != 0) {
					check = false;
					cnt++;
				}
			}
		}
		if (check) {
			break;
		}
		// bfs 빙산 분리됐는지 체크
		if (colapse()) {
			finish_time = current;
			break;
		}

		current++;

		// 빙산 녹이기
		melt();
	}

	if (finish_time == -1) {
		cout << 0 << "\n";
	}
	else cout << finish_time << "\n";

	return 0;
}