#include<iostream>

using namespace std;

int choose[10], N, M;
bool visited[10];

void dfs(int num, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << choose[i] << ' ';
		}
		cout << '\n';
	}

	for (int i = num; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			choose[cnt] = i;
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	dfs(1, 0);

	return 0;
}

// 조합의 개수 구하기 -> dfs를 통한 백트래킹 방식
// 방법 1. 오름차순 수열만 출력하도록 조건 생성 (check 변수)
/*
#include<iostream>
#include<algorithm>

using namespace std;

int choose[10], N, M;
bool visited[10];

void dfs(int cnt) {
	if (cnt == M) {
		int check = 0;
		for (int i = 0; i < M - 1; i++) {
			if (choose[i] > choose[i + 1])
				check = 1;
		}

		if (check == 0) {
			for (int i = 0; i < M; i++) {
				cout << choose[i] << ' ';
			}
			cout << '\n';
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			choose[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	dfs(0);

	return 0;
}
*/

// 방법 2. 재귀 호출에서, 현재 뽑은 원소가 이전값들은 고려하지 않게 for문의 i값도 함께 넘김