#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int tc;
		cin >> tc;
		unordered_map<int, int> um;
		for (int j = 0; j < 1000; j++) {
			int n;
			cin >> n;
			if (um.find(n) == um.end()) {
				um.insert({ n, 1 });
			}
			else {
				um[n]++;
			}
		}
		priority_queue<pair<int, int>> pq;
		for (auto m : um) {
			pq.push({ m.second, m.first });
		}
		cout << "#" << tc << " " << pq.top().second << "\n";
	}

	return 0;
}