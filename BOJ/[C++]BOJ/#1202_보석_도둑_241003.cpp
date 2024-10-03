#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<pair<int, int>> dia; // { 무게, 가격 }
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
	sort(bag.begin(), bag.end()); // 가방 오름차순
	sort(dia.begin(), dia.end()); // 보석 무게 오름차순

	priority_queue<int> pq;
	int j = 0; // pq에 담은 보석 수

	// 가방의 용량을 순차적으로 처리
	for (int i = 0; i < K; i++) {
		// 작은 용량 가방부터 담을 수 있는 보석 가격을 pq에 담기
		while (j < N && dia[j].first <= bag[i]) {
			pq.push(dia[j].second);
			j++;
		}

		// pq에서 가장 비싼 보석을 가방에 담기
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop(); // 담은 보석은 삭제, 남은 보석은 다음 가방에도 들어가므로 유지
		}
	}

	cout << sum;

	return 0;
}