#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int>arr;
	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		arr.push_back(x);
	}
	int sum = 0, max = 0;
	for (int i = 0; i < N-2; i++) {
		for (int j = i+1; j < N-1; j++) {
			for (int k = j+1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (max < sum && sum >= 10 && sum <= M)
					max = sum;
			}
		}
	}
	cout << max;
	return 0;
}