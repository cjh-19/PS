#include <bits/stdc++.h>

using namespace std;

int topni[4][8]; // 12시(0), 1(1), 2(2), 3, 4, 5, 6, 7
bool visited[4]; // 방문 정보
bool possible[3]; // 회전 가능 정보

int K;

// num: 회전 톱니 번호, dir: 회전 방향
// 재귀
void rotation(int num, int dir) {
	visited[num - 1] = true;

	// 본인 회전
	// 시계
	if (dir == 1) {
		int tmp = topni[num - 1][0];
		topni[num - 1][0] = topni[num - 1][7];
		topni[num - 1][7] = topni[num - 1][6];
		topni[num - 1][6] = topni[num - 1][5];
		topni[num - 1][5] = topni[num - 1][4];
		topni[num - 1][4] = topni[num - 1][3];
		topni[num - 1][3] = topni[num - 1][2];
		topni[num - 1][2] = topni[num - 1][1];
		topni[num - 1][1] = tmp;
	}
	// 반시계
	else if (dir == -1) {
		int tmp = topni[num - 1][0];
		topni[num - 1][0] = topni[num - 1][1];
		topni[num - 1][1] = topni[num - 1][2];
		topni[num - 1][2] = topni[num - 1][3];
		topni[num - 1][3] = topni[num - 1][4];
		topni[num - 1][4] = topni[num - 1][5];
		topni[num - 1][5] = topni[num - 1][6];
		topni[num - 1][6] = topni[num - 1][7];
		topni[num - 1][7] = tmp;
	}

	// 왼쪽 회전 판단
	if (num - 1 >= 1 && !visited[num - 2] && possible[num - 2]) {
		rotation(num - 1, -1 * dir);
	}

	// 오른쪽 회전 판단
	if (num + 1 <= 4 && !visited[num] && possible[num - 1]) {
		rotation(num + 1, -1 * dir);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			topni[i][j] = str[j] - '0'; // 0은 N, 1은 S
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int num, dir;
		fill(visited, visited + 4, false);
		fill(possible, possible + 3, false);

		// 맞닿은 자석이 다른 경우들만 possible을 true로
		for (int i = 0; i < 3; i++) {
			if (topni[i][2] != topni[i + 1][6]) {
				possible[i] = true;
			}
		}

		cin >> num >> dir;
		rotation(num, dir);
	}

	// 점수 계산
	int score = 0;
	for (int i = 0; i < 4; i++) {
		if (topni[i][0] == 1) score += pow(2, i);
	}

	cout << score;

	return 0;
}