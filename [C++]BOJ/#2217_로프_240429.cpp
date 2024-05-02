#include <iostream>
#include <algorithm>

using namespace std;

int n;
int input[100000];
int answer;

void solve() {
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input, input + n);
	for (int i = 0; i < n; i++) {
		answer = max(answer, (n - i) * input[i]);
	}
	cout << answer;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	solve();

	return 0;
}