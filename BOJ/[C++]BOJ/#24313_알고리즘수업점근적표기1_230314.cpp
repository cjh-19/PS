#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int a1, a0, c, n0;

	cin >> a1 >> a0 >> c >> n0;
	for (int i = n0; i <= 100; i++) {
		if (i * (c - a1) < a0) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;

	return 0;
}