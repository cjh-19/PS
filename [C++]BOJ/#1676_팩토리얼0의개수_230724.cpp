\#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, cnt = 0;
	cin >> N;
	for (int i = 5; i <= N; i+=5) {
		int tmp = i;
		while (tmp % 5 == 0) {
			cnt++;
			tmp /= 5;
		}
	}
	cout << cnt << "\n";

	return 0;
}