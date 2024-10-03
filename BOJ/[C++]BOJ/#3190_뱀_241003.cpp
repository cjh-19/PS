#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K, L; // 보드크기, 사과 개수, 방향 변환 횟수
int map[101][101];
queue<pair<int, char>> snmove;
deque<pair<int, int>> snake;

// 오른쪽0, 아래1, 왼쪽2, 위3
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int gametime = 0;

// 뱀 이동 함수
void move() {
	// 뱀의 시작 이동 방향
	int posnum = 0;

	int movetime = snmove.front().first;
	char movepos = snmove.front().second;
	snmove.pop();

	while (1) {
		gametime++;

		// 이동
		int nx = snake.front().first + dx[posnum];
		int ny = snake.front().second + dy[posnum];

		// 이동 위치가 벽이거나 자신이라면
		if (nx <= 0 || nx > N || ny <= 0 || ny > N) return;
		else if (map[nx][ny] == 2) return;

		// 사과라면
		if (map[nx][ny] == 1) {
			map[nx][ny] = 2;
			snake.push_front({ nx,ny });
			;
		}
		else if (map[nx][ny] == 0) {
			map[nx][ny] = 2;
			snake.push_front({ nx,ny });
			// 꼬리 자르기
			int tailx = snake.back().first;
			int taily = snake.back().second;
			snake.pop_back();
			map[tailx][taily] = 0;
		}

		// 방향 전환
		if (gametime == movetime) {
			if (movepos == 'L') { // 왼쪽 90도 회전
				posnum--;
				if (posnum < 0) posnum = 3;
			}
			else if (movepos == 'D') { // 오른쪽 90도 회전
				posnum++;
				if (posnum > 3) posnum = 0;
			}
			if (snmove.empty()) continue;
			movetime = snmove.front().first;
			movepos = snmove.front().second;
			snmove.pop();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1; // 1은 사과
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int n;
		char ch;
		cin >> n >> ch;
		snmove.push({ n, ch });
	}
	map[1][1] = 2; // 뱀의 첫 위치 (1, 1)
	snake.push_front({ 1,1 });

	move(); // 뱀 이동

	cout << gametime;

	return 0;
}