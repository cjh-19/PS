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

// ������ ���� ���ϱ� -> dfs�� ���� ��Ʈ��ŷ ���
// ��� 1. �������� ������ ����ϵ��� ���� ���� (check ����)
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

// ��� 2. ��� ȣ�⿡��, ���� ���� ���Ұ� ���������� ������� �ʰ� for���� i���� �Բ� �ѱ�