#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N * 2 - 1; i++) {
		if (i < N) {
			for (int k = 0; k < N - 1 - i; k++)
				cout << " ";
			for (int k = 0; k < 2 * i + 1; k++)
				cout << "*";
			cout << "\n";
		}
		else {
			for (int k = 0; k < i + 1 - N; k++)
				cout << " ";
			for (int k = 0; k < 4 * N - 2 * i - 3; k++)
				cout << "*";
			cout << "\n";
		}
	}
	return 0;
}