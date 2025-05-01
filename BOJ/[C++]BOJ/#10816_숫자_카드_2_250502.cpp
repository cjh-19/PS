#include <iostream>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<int, int> card;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		card[n]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		cout << card[n] << " ";
	}

	return 0;
}