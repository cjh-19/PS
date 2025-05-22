#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[8];

void dfs(int idx, vector<int> v) {
	if (idx == M) {
		for (int i = 0; i < M - 1; i++) {
			cout << v[i] << " ";
		}
		cout << v[M - 1] << "\n";
		return;
	}

	set<int> s;
	for (int i = 0; i < N; i++) {
		if (v[idx - 1] > arr[i]) continue;
		if (s.find(arr[i]) != s.end()) continue;
		s.insert(arr[i]);

		v.push_back(arr[i]);
		dfs(idx + 1, v);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	set<int> s;
	vector<int> v;
	for (int i = 0; i < N; i++) {

		if (s.find(arr[i]) != s.end()) continue;
		s.insert(arr[i]);
		v.push_back(arr[i]);
		dfs(1, v);
		v.pop_back();
	}

	return 0;
}