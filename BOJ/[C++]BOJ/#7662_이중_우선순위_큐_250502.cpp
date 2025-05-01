#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int K;
		cin >> K;
		priority_queue<int> maxQ; // 최대힙
		priority_queue<int, vector<int>, greater<int>> minQ; // 최소힙
		map<int, int> m; // 숫자 n의 삽입(+1) 삭제(-1) 관리

		for (int j = 0; j < K; j++) {
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') {
				maxQ.push(n);
				minQ.push(n);
				m[n]++;
			}
			else if (c == 'D') {
				if (n == 1) {
					while (!maxQ.empty()) {
						int top = maxQ.top();
						maxQ.pop();
						// top 숫자가 아직 있다면 삭제 후 0이라면 m에서 제거
						if (m[top] > 0) {
							m[top]--;
							if (m[top] == 0) m.erase(top);
							break;
						}
					}
				}
				else if (n == -1) {
					while (!minQ.empty()) {
						int top = minQ.top();
						minQ.pop();
						// top 숫자가 아직 있다면 삭제 후 0이라면 m에서 제거
						if (m[top] > 0) {
							m[top]--;
							if (m[top] == 0) m.erase(top);
							break;
						}
					}
				}
			}
		}

		int maxValue;
		int minValue;
		bool maxCheck = false;
		bool minCheck = false;

		while (!maxQ.empty()) {
			int top = maxQ.top();
			if (m[top] > 0) {
				maxValue = top;
				maxCheck = true;
				break;
			}
			maxQ.pop();
		}

		while (!minQ.empty()) {
			int top = minQ.top();
			if (m[top] > 0) {
				minValue = top;
				minCheck = true;
				break;
			}
			minQ.pop();
		}

		if (maxCheck && minCheck) cout << maxValue << " " << minValue << "\n";
		else cout << "EMPTY" << "\n";
	}

	return 0;
}