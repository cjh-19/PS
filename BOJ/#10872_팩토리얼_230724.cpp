#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, fac = 1;
	cin >> N;
	if (N == 0) {
		cout << 1 << "\n";
		return 0;
	}
	for (int i = 2; i <= N; i++) {
		fac *= i;
	}
	cout << fac << "\n";
	return 0;
}