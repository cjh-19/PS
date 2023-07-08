#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, k, n;
	int arr[15][14] = { 0, };
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 14; j++) {
			if (j == 0)
				arr[i][j] = 1;
			else if (i == 0)
				arr[i][j] = j + 1;
			else if (j != 0 && i != 0) {
				for (int k = 0; k <= j; k++)
					arr[i][j] += arr[i - 1][k];
			}
		}
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << arr[k][n - 1] << "\n";
	}
	return 0;
}