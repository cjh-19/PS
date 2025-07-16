#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> magic;

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << magic[i][j] << " ";
		}
		cout << "\n";
	}
}

void make() {
	int r = 0;
	int c = N / 2;

	for (int i = 1; i <= N * N; i++) {
		magic[r][c] = i;

		int tempR = r;
		int tempC = c;

		r = (r - 1 + N) % N;
		c = (c - 1 + N) % N;

		if (magic[r][c] != 0) {
			r = (tempR + 1) % N;
			c = tempC;
		}
	}
}

// 1:2:1 로 나누고 2인 구간들 대칭 교환
void double_even() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			magic[i][j] = i * N + j + 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i % 4 == j % 4) || (i % 4 + j % 4 == 3)) {
				magic[i][j] = N * N + 1 - magic[i][j];
			}
		}
	}
}

// 4구역으로 나눠서 make() 4번 호출
void singly_even() {
	int half = N / 2;
	int k = N / 4;
	int qSize = half * half;

	// half * half 의 홀수 마방진
	vector<vector<int>> sub(half, vector<int>(half));
	int r = 0;
	int c = N / 4;

	for (int i = 1; i <= qSize; i++) {
		sub[r][c] = i;

		int tempR = r;
		int tempC = c;

		r = (r - 1 + half) % half;
		c = (c - 1 + half) % half;

		if (sub[r][c] != 0) {
			r = (tempR + 1) % half;
			c = tempC;
		}
	}

	// 네 개 분할 영역에 값 채우기
	// A | C
	// D | B
	for (int i = 0; i < half; ++i) {
		for (int j = 0; j < half; ++j) {
			magic[i][j] = sub[i][j];             // A: +0
			magic[i][j + half] = sub[i][j] + 2 * qSize;   // C: +2q
			magic[i + half][j] = sub[i][j] + 3 * qSize;   // D: +3q
			magic[i + half][j + half] = sub[i][j] + qSize;  // B: +1q
		}
	}

	// A와 D의 왼쪽 k개 열 교환
	for (int i = 0; i < half; i++) {
		for (int j = 0; j < k; j++) {
			swap(magic[i][j], magic[i + half][j]);
		}
	}

	// C와 B의 오른쪽 k-1개 열 교환
	for (int i = 0; i < half; i++) {
		for (int j = half - (k - 1); j < half; j++) {
			swap(magic[i][j + half], magic[i + half][j + half]);
		}
	}

	// 중간 3과 0 칸 교환
	swap(magic[k][0], magic[k + half][0]);
	swap(magic[k][k], magic[k + half][k]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	magic.resize(N, vector<int>(N, 0));

	if (N % 2 == 1) make();
	else if (N % 4 == 0) double_even();
	else if (N % 2 == 0 && N % 4 != 0) singly_even();
	print();

	return 0;
}