#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[8];

void dfs(int idx, vector<int> v, vector<bool> visited) {
	if (idx == M) {
		for (int i = 0; i < M - 1; i++) {
			cout << v[i] << " ";
		}
		cout << v[M - 1] << "\n";
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;

		v.push_back(arr[i]);
		visited[i] = true;
		dfs(idx + 1, v, visited);
		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		vector<int> v;
		vector<bool> visited(N);

		v.push_back(arr[i]);
		visited[i] = true;
		dfs(1, v, visited);
		v.pop_back();
		visited[i] = false;
	}

	return 0;
}