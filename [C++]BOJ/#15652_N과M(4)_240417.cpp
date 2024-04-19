#include<iostream>

using namespace std;

int choose[10], N, M;
bool visited[10];

void dfs(int num, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << choose[i] << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = num; i <= N; i++) {
		visited[i] = true;
		choose[cnt] = i;
		dfs(i, cnt + 1);
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	dfs(1, 0);

	return 0;
}