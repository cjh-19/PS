#include<iostream>
#include<vector>

using namespace std;

vector<int> result;
int N, M;

void dfs(int num, int cnt);

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	dfs(1, 0);

	return 0;
}

void dfs(int num, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << ' ';
		}
		cout << "\n";
	}
	else {
		for (int i = num; i <= N; i++) {
			result.push_back(i);
			dfs(i, cnt + 1);
			result.pop_back();
		}
	}
}