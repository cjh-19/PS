#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long N;
	cin >> N;
	long long t[6];
	long long T, P;
	long long mint = 0;
	for (int i = 0; i < 6; i++) {
		cin >> t[i];
	}
	cin >> T >> P;

	for (int i = 0; i < 6; i++) {
		mint += (t[i] + T - 1) / T;
	}

	cout << mint << "\n" << N / P << " " << N % P;

	return 0;
}