#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 오름차순
struct cmp {
	bool operator()(int x, int y) {
		return x > y;
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	priority_queue<int, vector<int>, cmp> pq; // minHeap

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		pq.push(n);
	}

	int sum = 0;
	while (!pq.empty()) {
		if (pq.size() == 1) break;
		int n1 = pq.top();
		pq.pop();
		int n2 = pq.top();
		pq.pop();
		pq.push(n1 + n2);
		sum += n1 + n2;
	}

	cout << sum;

	return 0;
}