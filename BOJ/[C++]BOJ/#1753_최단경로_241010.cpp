#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int V, E;
int startNode;
vector<vector<pair<int, int>>> node; // {연결 노드, 가중치}
vector<int> dist;

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {거리, 노드번호}

	dist[startNode] = 0; // 시작 노드 거리 0 설정
	pq.push({ 0, startNode });

	while (!pq.empty()) {
		int dis = pq.top().first;
		int nodeNum = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[nodeNum].size(); i++) { // i : nodeNum의 인접 노드
			int next_node = node[nodeNum][i].first; // 연결 노드 번호
			int next_dis = dis + node[nodeNum][i].second; // 지금까지 가중치 + 연결 노드와의 가중치

			if (dist[next_node] > next_dis) {
				dist[next_node] = next_dis;
				pq.push({ next_dis, next_node }); // 최소 거리라면 큐에 추가
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> V >> E >> startNode;

	node.resize(V + 1);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		node[u].push_back({ v,w });
	}

	dist.resize(V + 1, INT_MAX);

	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX) cout << "INF" << "\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}