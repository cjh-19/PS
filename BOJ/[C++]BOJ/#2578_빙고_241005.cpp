#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, pair<int, int>> board;
bool visited[5][5];

// visited 배열에 선이 세개 그어지는지 체크
bool bingo() {
	int count = 0;
	int dia1 = 0; // 대각선이 되는지 체크
	int dia2 = 0; // 대각선이 되는지 체크
	for (int i = 0; i < 5; i++) {
		// 열 빙고 체크
		if (visited[0][i] && visited[1][i] && visited[2][i] && visited[3][i] && visited[4][i])
			count++;

		// 행 빙고 체크
		if (visited[i][0] && visited[i][1] && visited[i][2] && visited[i][3] && visited[i][4])
			count++;

		// 대각선 빙고 체크
		if (!visited[i][i]) dia1 = -1;
		if (!visited[i][4 - i]) dia2 = -1;
	}
	if (dia1 == 0) count++;
	if (dia2 == 0) count++;

	if (count >= 3) return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int num = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int n;
			cin >> n;
			board.insert({ n, {i,j} });
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int n;
			cin >> n;
			pair<int, int> xy = board[n];
			visited[xy.first][xy.second] = true;
			if (bingo() && num == 0) {
				num = i * 5 + j + 1;
			}
		}
	}

	cout << num;

	return 0;
}