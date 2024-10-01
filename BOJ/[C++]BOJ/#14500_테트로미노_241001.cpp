#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
int map[500][500];
bool visited[500][500];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int maxNum = 0;

void dfs(int startX, int startY, int count, int sum) {
	if (count == 4) {
		maxNum = max(sum, maxNum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = startX + dx[i];
		int ny = startY + dy[i];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
			visited[nx][ny] = true;
			dfs(nx, ny, count + 1, sum + map[nx][ny]);
			visited[nx][ny] = false;
		}
	}
}

void Tdfs(int startX, int startY) {
	// 중앙 지점에서 상 하 좌 우 중 3개 더하기
	for (int i = 0; i < 4; i++) {
		int sum = map[startX][startY];
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;

			int nx = startX + dx[j];
			int ny = startY + dy[j];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				sum += map[nx][ny];
			}
		}
		maxNum = max(sum, maxNum);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	// ㅗ 모양을 제외하고는 dfs 가능
	// ㅗ 모양은 따로 함수 두기
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		for (int j = 0; j < M; j++) {
			cin >> num;
			map[i][j] = num;
		}
	}

	// 모든 위치에서 dfs 하기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			dfs(i, j, 0, 0);
			Tdfs(i, j);
		}
	}

	cout << maxNum << "\n";

	return 0;
}