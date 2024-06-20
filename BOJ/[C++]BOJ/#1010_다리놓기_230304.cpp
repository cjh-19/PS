#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M, sum=1, z=1;
		cin >> N >> M;
		for (int j = M-N+1; j <= M; j++) {
			sum *= j;
			sum /= z; z++;
		}
		cout << sum << endl;
	}

	return 0;
}