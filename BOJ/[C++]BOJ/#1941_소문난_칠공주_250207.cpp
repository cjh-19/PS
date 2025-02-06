#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[25]; // �̴ټ�(S) 1, �ӵ���(Y) 0
bool visited[25] = { false, };
int resultCnt = 0;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// people�� ���μ��η� �̾����ִ��� Ȯ�� -> �´ٸ� ����� �� ����
void bfs(vector<pair<int, int>> people) {
	// ĥ���� �¼�
	int pboard[5][5] = { 0, };
	bool check[5][5] = { false, };
	for (int i = 0; i < 7; i++) {
		pboard[people[i].first][people[i].second] = 1;
	}
	queue<pair<int, int>> q;
	q.push({ people[0].first, people[0].second });
	check[q.front().first][q.front().second] = true;

	int count = 0;

	while (!q.empty()) {
		int xpos = q.front().first;
		int ypos = q.front().second;
		q.pop();

		count++;

		// �̾����ִٸ� ����� �� ����
		if (count == 7) {
			resultCnt++;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = xpos + dx[i];
			int ny = ypos + dy[i];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || check[nx][ny]) continue;

			if (pboard[nx][ny] == 1) {
				q.push({ nx, ny });
				check[nx][ny] = true;
			}
		}
	}
}

// pos�� ���� ��ġ, cnt�� ���� �ο�
void dfs(int pos, int cnt, vector<pair<int, int>> people) {
	if (cnt == 7 && people.size() == 7) {
		int scnt = 0;
		for (int i = 0; i < 7; i++) {
			int x = people[i].first, y = people[i].second;
			if (board[x * 5 + y] == 1) scnt++;
		}
		if (scnt >= 4) bfs(people);
		return;
	}

	for (int i = pos; i < 25; i++) {
		// �̹� �湮������ �н�
		if (visited[i]) continue;

		int x = i / 5, y = i % 5;
		visited[i] = true;
		people.push_back({ x,y });
		dfs(i, cnt + 1, people);
		people.pop_back();
		visited[i] = false;
	}
}

void solve() {
	// dfs�� 7�� ���� & 1�� 4�� �̻����� �Ǵ�
	// true�� bfs�� ���� �̾����ִ��� Ȯ��
	vector<pair<int, int>> people;
	dfs(0, 0, people);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 5; j++) {
			if (str[j] == 'S') board[i * 5 + j] = 1;
			else board[i * 5 + j] = 0;
		}
	}

	solve();
	cout << resultCnt;

	return 0;
}