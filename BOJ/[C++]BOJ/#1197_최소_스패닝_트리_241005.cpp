#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int V, E;
vector<tuple<int, int, int>> node;
int parent[10001]; // 각 노드의 부모노드를 저장
int weightCost = 0;

// 가중치 크기로 오름차순 정렬
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	return get<2>(a) < get<2>(b);
}

// 부모노드를 찾는 함수
int find(int node) {
	if (parent[node] == node) return node;
	return parent[node] = find(parent[node]); // 경로 압축 -> 부모노드를 빨리 찾기 위해서
	//return find(parent[node]); -> 시간 초과
}

// n1에 n2 집합을 붙이는 함수 -> n2의 부모노드를 n1의 부모를 가르키도록 설정
void uni(int n1, int n2) {
	n1 = find(n1);
	n2 = find(n2);
	parent[n2] = n1;
}

// 두 노드의 부모 노드가 같은지 확인
bool sameParent(int n1, int n2) {
	n1 = find(n1);
	n2 = find(n2);
	if (n1 == n2) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		node.push_back({ x, y, w });
	}
	sort(node.begin(), node.end(), cmp);

	// 유니온 파인드
	// 초기화(자기자신이 부모노드로) -> 서로 연결이 안된 상태
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	// 가중치가 낮은 노드부터 시작
	for (int i = 0; i < node.size(); i++) {
		int node1 = get<0>(node[i]);
		int node2 = get<1>(node[i]);

		// 두 노드가 같지 않다면 추가
		if (!sameParent(node1, node2)) {
			// node2의 부모노드가 node1의 부모노드를 가르키도록 설정
			uni(node1, node2);
			weightCost += get<2>(node[i]);
		}
	}

	cout << weightCost;

	return 0;
}