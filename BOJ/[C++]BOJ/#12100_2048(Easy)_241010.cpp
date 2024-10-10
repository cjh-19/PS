#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int N;
int maxNum = 0;

// 상 하 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 방향에 맞게 보드내의 숫자 이동
vector<vector<int>> move(vector<vector<int>> board, int dx, int dy) {
	// 위로 이동
	if (dx == -1 && dy == 0) {
		for (int j = 0; j < N; j++) {
			queue<int> Q;
			for (int i = 0; i < N; i++) {
				if (board[i][j] != 0) {
					Q.push(board[i][j]);
					board[i][j] = 0; // 큐에 넣고 0으로 설정
				}
			}
			// 한 열이 추가 되면
			int row = 0; // 첫번째 행부터 채우기
			while (!Q.empty()) {
				int num = Q.front();
				Q.pop();

				if (board[row][j] == 0) // 0이면 값 넣기(이동)
					board[row][j] = num;
				else if (board[row][j] == num) { // 비교 값이 같은 값이면
					board[row][j] = num + num;
					row++; // 합친 행이므로 다음 행 비교를 위해 이동
				}
				else { // 값이 이미 있고 다른 값이라면
					row++; // 행 늘리고
					board[row][j] = num; // 저장
				}
			}
		}
	}
	// 아래로 이동
	else if (dx == 1 && dy == 0) {
		for (int j = 0; j < N; j++) {
			queue<int> Q;
			for (int i = N - 1; i >= 0; i--) {
				if (board[i][j] != 0) {
					Q.push(board[i][j]);
					board[i][j] = 0; // 큐에 넣고 0으로 설정
				}
			}
			// 한 열이 추가 되면
			int row = N - 1; // 맨 아래 행부터 채우기
			while (!Q.empty()) {
				int num = Q.front();
				Q.pop();

				if (board[row][j] == 0) // 0이면 값 넣기(이동)
					board[row][j] = num;
				else if (board[row][j] == num) { // 비교 값이 같은 값이면
					board[row][j] = num + num;
					row--; // 합친 행이므로 다음 행 비교를 위해 이동
				}
				else { // 값이 이미 있고 다른 값이라면
					row--; // 행 늘리고
					board[row][j] = num; // 저장
				}
			}
		}
	}
	// 왼쪽으로 이동
	else if (dx == 0 && dy == -1) {
		for (int i = 0; i < N; i++) {
			queue<int> Q;
			for (int j = 0; j < N; j++) {
				if (board[i][j] != 0) {
					Q.push(board[i][j]);
					board[i][j] = 0; // 큐에 넣고 0으로 설정
				}
			}
			// 한 행이 추가 되면
			int col = 0; // 첫번째 열부터 채우기
			while (!Q.empty()) {
				int num = Q.front();
				Q.pop();

				if (board[i][col] == 0) // 0이면 값 넣기(이동)
					board[i][col] = num;
				else if (board[i][col] == num) { // 비교 값이 같은 값이면
					board[i][col] = num + num;
					col++; // 합친 열이므로 다음 열 비교를 위해 이동
				}
				else { // 값이 이미 있고 다른 값이라면
					col++; // 열 늘리고
					board[i][col] = num; // 저장
				}
			}
		}
	}
	// 오른쪽으로 이동
	else if (dx == 0 && dy == 1) {
		for (int i = 0; i < N; i++) {
			queue<int> Q;
			for (int j = N - 1; j >= 0; j--) {
				if (board[i][j] != 0) {
					Q.push(board[i][j]);
					board[i][j] = 0; // 큐에 넣고 0으로 설정
				}
			}
			// 한 행이 추가 되면
			int col = N - 1; // 마지막 열부터 채우기
			while (!Q.empty()) {
				int num = Q.front();
				Q.pop();

				if (board[i][col] == 0) // 0이면 값 넣기(이동)
					board[i][col] = num;
				else if (board[i][col] == num) { // 비교 값이 같은 값이면
					board[i][col] = num + num;
					col--; // 합친 열이므로 다음 열 비교를 위해 이동
				}
				else { // 값이 이미 있고 다른 값이라면
					col--; // 열 줄이고
					board[i][col] = num; // 저장
				}
			}
		}
	}

	return board;
}

void dfs(vector<vector<int>> board, int count) {
	if (count == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maxNum = max(maxNum, board[i][j]);
			}
		}
		return;
	}

	// 상하좌우로 이동
	for (int i = 0; i < 4; i++) {
		// 이동 방향
		int nx = dx[i];
		int ny = dy[i];

		dfs(move(board, nx, ny), count + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	vector<vector<int>> board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	dfs(board, 0);

	cout << maxNum;

	return 0;
}