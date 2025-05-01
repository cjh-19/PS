#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int N;
vector<vector<int>> board;

// 상 좌 우 하
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

struct Shark {
	int size = 2;
	int eatCnt = 0; // 현재까지 먹은 물고기 크기 합
	pair<int, int> xy;
	int timeCnt = 0;
};

Shark shark;

// 거리, x, y
tuple<int, int, int> bfs() {
	vector<vector<int>> dist(N, vector<int>(N, -1));

	queue<pair<int, int>> q;
	q.push({ shark.xy.first, shark.xy.second });
	dist[shark.xy.first][shark.xy.second] = 0; // 상어 본인과의 거리는 0

	vector<tuple<int, int, int>> fishList; // 먹을 수 있는 물고기 목록

	while (!q.empty()) {
		pair<int, int> xy = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = xy.first + dx[i];
			int ny = xy.second + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (dist[nx][ny] != -1) continue; // -1이 아니면 이미 측정한 물고기
			if (board[nx][ny] > shark.size) continue; // 상어보다 크면 못지나감

			dist[nx][ny] = dist[xy.first][xy.second] + 1; // 이전 위치에서 +1

			// 먹을 수 있는 물고기
			if (board[nx][ny] > 0 && board[nx][ny] < shark.size) {
				fishList.push_back({ dist[nx][ny], nx, ny });
			}

			q.push({ nx,ny });
		}
	}

	if (fishList.empty()) return { -1,-1,-1 }; // 먹을 수 있는 물고기가 없는 경우

	sort(fishList.begin(), fishList.end()); // 거리, x, y 순으로 정렬
	return fishList[0];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	board.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				shark.xy = { i,j };
			}
		}
	}

	while (1) {
		tuple<int, int, int> fishInfo = bfs();

		if (get<0>(fishInfo) == -1) break;

		// 상어 이동
		board[shark.xy.first][shark.xy.second] = 0; // 기존 상어 위치를 빈칸으로 변경
		shark.xy.first = get<1>(fishInfo);
		shark.xy.second = get<2>(fishInfo);


		// 물고기 먹기
		board[get<1>(fishInfo)][get<2>(fishInfo)] = 0;
		shark.eatCnt++;
		shark.timeCnt += get<0>(fishInfo); // 거리만큼 시간 증가

		if (shark.eatCnt == shark.size) {
			shark.size++;
			shark.eatCnt = 0;
		}
	}

	cout << shark.timeCnt;

	return 0;
}