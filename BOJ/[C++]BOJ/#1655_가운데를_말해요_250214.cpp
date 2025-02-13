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
	// �ִ����� ��Ʈ�� �ּ����� ��Ʈ���� ū��� ����
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

		// �ִ����� ũ��� �ּ����� ũ�⺸�� �ϳ� ũ�ų� ����
		heapPush(n);

		// �ִ����� top�� �ּ����� top���� �۰ų� ����
		// top �� ��, �� ���� �������� ���ϸ� swap
		topSwap();

		// �ִ����� top�� �߰���
		cout << maxHeap.top() << "\n";
	}

	return 0;
}