#include <bits/stdc++.h>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void heapPush(int n) {
	if (maxHeap.size() == minHeap.size()) maxHeap.push(n);
	else if (maxHeap.size() == minHeap.size() + 1) minHeap.push(n);
}

void topSwap() {
	if (maxHeap.empty() || minHeap.empty()) return;
	// 최대힙의 루트가 최소힙의 루트보다 큰경우 스왑
	if (maxHeap.top() > minHeap.top()) {
		int maxtmp = maxHeap.top();
		int mintmp = minHeap.top();

		maxHeap.pop();
		minHeap.pop();
		maxHeap.push(mintmp);
		minHeap.push(maxtmp);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		// 최대힙의 크기는 최소힙의 크기보다 하나 크거나 같음
		heapPush(n);

		// 최대힙의 top은 최소힙의 top보다 작거나 같음
		// top 비교 후, 위 조건 만족하지 못하면 swap
		topSwap();

		// 최대힙의 top이 중간값
		cout << maxHeap.top() << "\n";
	}

	return 0;
}