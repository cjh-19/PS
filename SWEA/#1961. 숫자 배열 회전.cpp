#include <iostream>

using namespace std;

int N;

int board[25][25];

// (x, y) -> (N - 1 - y, x)
// num: 0 => 제자리 회전
// num: 1,2 => 왼쪽 보드 회전
void rotation(int num) {
	int newBoard[25][25];
	int targetNum = 0;

	if (num != 0) {
		targetNum = num - 1;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			newBoard[j][N - 1 - i] = board[i][N * targetNum + j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][N * num + j] = newBoard[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int n;
				cin >> n;
				for (int k = 0; k < 3; k++) {
					board[i][N * k + j] = n;
				}
			}
		}

		// 회전
		rotation(0);
		rotation(1);
		rotation(2);

		cout << "#" << t << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < N; k++) {
					cout << board[i][N * j + k];
				}
				if (j < 2) cout << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}