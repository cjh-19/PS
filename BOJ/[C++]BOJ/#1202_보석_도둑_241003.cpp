#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<pair<int, int>> dia; // { ����, ���� }
vector<int> bag;

long long sum = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;
		dia.push_back({ m, v });
	}
	for (int i = 0; i < K; i++) {
		int c;
		cin >> c;
		bag.push_back(c);
	}
	sort(bag.begin(), bag.end()); // ���� ��������
	sort(dia.begin(), dia.end()); // ���� ���� ��������

	priority_queue<int> pq;
	int j = 0; // pq�� ���� ���� ��

	// ������ �뷮�� ���������� ó��
	for (int i = 0; i < K; i++) {
		// ���� �뷮 ������� ���� �� �ִ� ���� ������ pq�� ���
		while (j < N && dia[j].first <= bag[i]) {
			pq.push(dia[j].second);
			j++;
		}

		// pq���� ���� ��� ������ ���濡 ���
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop(); // ���� ������ ����, ���� ������ ���� ���濡�� ���Ƿ� ����
		}
	}

	cout << sum;

	return 0;
}