#include <iostream>

using namespace std;

int map[9][9];
int zeroCnt = 0;

// map에서 (x,y)에 해당 숫자(num)가 들어가는게 가능한지 체크
bool numCheck(int x, int y, int num) {
	// 가로 세로에 해당 숫자가 있는지 체크
	for (int i = 0; i < 9; i++) {
		if (map[x][i] == num || map[i][y] == num) return false;
	}

	// 해당 구역 9칸에 해당 숫자가 있는지 체크
	// 구역 설정
	int startx = (x / 3) * 3;
	int starty = (y / 3) * 3;
	for (int i = startx; i < startx + 3; i++) {
		for (int j = starty; j < starty + 3; j++) {
			if (map[i][j] == num) return false;
		}
	}

	return true;
}

void dfs(int count) {
	if (count == zeroCnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}

		exit(0);
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) {
				for (int num = 1; num <= 9; num++) {
					if (numCheck(i, j, num)) {
						map[i][j] = num;
						dfs(count + 1);
						map[i][j] = 0;
					}
				}
				return; // 빈칸을 채우면 반환
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) zeroCnt++;
		}
	}

	dfs(0);

	return 0;
}