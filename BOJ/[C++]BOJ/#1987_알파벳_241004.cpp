#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int R, C;
char map[20][20];
bool alpha[26];

int moveCnt = 0;

void dfs(int x, int y, int cnt) {
	moveCnt = max(moveCnt, cnt);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < R && ny >= 0 && ny < C && !alpha[map[nx][ny] - 'A']) {
			alpha[map[nx][ny] - 'A'] = true;
			dfs(nx, ny, cnt + 1);
			alpha[map[nx][ny] - 'A'] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j];
		}
	}

	alpha[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);

	cout << moveCnt;

	return 0;
}