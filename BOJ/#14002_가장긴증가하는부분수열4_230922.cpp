#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	vector<int> arr(N + 1);
	vector<vector<int>> vt(N + 1);

	vt[0].push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j] && vt[i].size() < vt[j].size()) {
				vt[i].push_back(arr[j]);
			}
		}
		vt[i].push_back(arr[i]);
	}
	int max = 0, maxnum = 0;;
	for (int i = 0; i < N; i++) {
		if (max < vt[i].size()) {
			max = vt[i].size();
			maxnum = i;
		}
	}
	cout << max << "\n";
	for (int i = 0; i < vt[maxnum].size(); i++) {
		cout << vt[maxnum][i] << " ";
	}

	return 0;
}