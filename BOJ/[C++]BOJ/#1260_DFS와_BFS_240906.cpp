#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N; // 정점 수
int M; // 간선 수
int V; // 시작 정점 번호
int visitedDfs[1001];
int visitedBfs[1001];
vector<int> graph[1001];
queue<int> Q;

void dfs(int V) {
	visitedDfs[V] = true;

	cout << V << " ";
	for (int i = 0; i < graph[V].size(); i++) {
		if (!visitedDfs[graph[V][i]]) {
			dfs(graph[V][i]);
		}
	}
}

void bfs(int V) {
	Q.push(V);
	visitedBfs[V] = true;

	while (!Q.empty()) {
		int front = Q.front();
		Q.pop();
		cout << front << " ";
		for (int i = 0; i < graph[front].size(); i++) {
			if (!visitedBfs[graph[front][i]]) {
				Q.push(graph[front][i]);
				visitedBfs[graph[front][i]] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int first;
		int second;
		cin >> first >> second;
		graph[first].push_back(second);
		graph[second].push_back(first);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);
	cout << "\n";
	bfs(V);
	cout << "\n";

	return 0;
}