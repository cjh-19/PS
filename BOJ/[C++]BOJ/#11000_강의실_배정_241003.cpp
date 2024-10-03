#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	vector<pair<int, int>> stu;
	priority_queue<int, vector<int>, greater<>> pq; // 오름차순 -> 가장 빨리 끝나는 수업을 보기 위해

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, t;
		cin >> s >> t;
		stu.push_back({ s, t });
	}
	sort(stu.begin(), stu.end()); // 오름 차순

	// 가장 빨리 끝나는 수업에 이어서 시작할 강의 교체 or 새로운 강의실 넣기

	// 끝나는 시간(t)을 pq에 담고, 시작시간(s)이 pq의 top(가장 작은)보다 크거나 같다면  pop
	// 새로 들어올 수업을 시작할 수 있으므로 pop하는 것
	for (int i = 0; i < stu.size(); i++) {
		pq.push(stu[i].second);
		if (pq.top() <= stu[i].first) pq.pop();
	}

	cout << pq.size();

	return 0;
}