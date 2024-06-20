#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x = i, count = 0, sum = i;
		while (x != 0) {
			x /= 10;
			count++;
		}
		x = i;
		for (int j = 0; j < count; j++) {
			sum += x % 10;
			x /= 10;
		}
		if (sum == N) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}