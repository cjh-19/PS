#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> tree(100001);
int parent[100001];

void bfs(int root) {
	queue<int> q;
	bool visited[100001] = { false, };
	q.push(root);
	visited[root] = true;

	while (!q.empty()) {
		int curNum = q.front();
		q.pop();

		for (int j = 0; j < tree[curNum].size(); j++) {
			if (visited[tree[curNum][j]]) continue;

			q.push(tree[curNum][j]);
			parent[tree[curNum][j]] = curNum;
			visited[tree[curNum][j]] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		tree[n1].push_back(n2);
		tree[n2].push_back(n1);
	}

	bfs(1);

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}