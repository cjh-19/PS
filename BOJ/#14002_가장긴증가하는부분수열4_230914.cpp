#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	vector<int> arr, dp;
	vector<vector<int>> vt(1000);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	dp.push_back(1);
	for (int i = 1; i < N; i++) {
		dp.push_back(0);
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j]) {
				dp[i] = dp[j];
			}
		}
		dp[i]++;
		vt[i].push_back(arr[i]);
	}
	int max = 0, k = 0;;
	for (int i = 0; i < N; i++) {
		if (max < dp[i]) {
			max = dp[i];
			k = i;
		}
	}
	cout << max << "\n";
	for (int i = 0; i < vt[k].size(); i++) {
		cout << vt[k][i] << " ";
	}

	return 0;
}

// 아이디어 : 2차원 배열을 통해서 각 값에 수를 저장