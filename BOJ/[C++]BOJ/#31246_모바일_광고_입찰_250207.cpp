#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return (a.first - a.second) > (b.first - b.second);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K;
	vector<pair<int, int>> v;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end(), cmp);

	int kcnt = 0;
	int X = 0;
	for (int i = 0; i < N; i++) {
		if (kcnt == K) break;

		if (v[i].first >= v[i].second) kcnt++;
		else {
			X = max(X, v[i].second - v[i].first);
			kcnt++;
		}
	}

	cout << X;

	return 0;
}