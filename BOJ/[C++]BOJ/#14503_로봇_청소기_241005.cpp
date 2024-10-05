#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int map[50][50];
int cleanCnt = 0; // 청소한 칸 개수

// 상(0) 우(1) 하(2) 좌(3)
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int x, int y, int dir) {
	queue<tuple<int, int, int>> q;
	q.push({ x,y,dir });
	map[x][y] = 2; // 청소하면 2로 설정
	cleanCnt++;

	while (!q.empty()) {
		int xpos = get<0>(q.front());
		int ypos = get<1>(q.front());
		int d = get<2>(q.front());
		q.pop();

		bool isclean = false;
		for (int i = 0; i < 4; i++) {
			// 반시계 90도 회전
			int nd = (d + 3) % 4;
			int nx = xpos + dx[nd];
			int ny = ypos + dy[nd];

			// 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0) {
				isclean = true;
				q.push({ nx, ny, nd });
				map[nx][ny] = 2;
				cleanCnt++;
				break;
			}
			d = nd; // 못가면 한번더 회전
		}
		if (!isclean) { // 주변 4칸 중 청소되지 않은 빈칸이 없는 경우
			int nd = (d + 2) % 4; // 180도 회전
			int nx = xpos + dx[nd];
			int ny = ypos + dy[nd];

			// 후진 가능하다면
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 2) {
				q.push({ nx, ny, d });
			}
			else break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	int startx, starty, dir;
	cin >> startx >> starty >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	bfs(startx, starty, dir);

	cout << cleanCnt;

	return 0;
}