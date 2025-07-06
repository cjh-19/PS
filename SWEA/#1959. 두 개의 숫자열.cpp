#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int maxline(vector<int> A, vector<int> B) {
	int sum = INT_MIN;

	int startpos = 0;
	int endpos = A.size() - 1;

	int tmp = 0;
	for (int i = startpos; i <= endpos; i++) {
		tmp += A[i - startpos] * B[i];
	}
	sum = max(sum, tmp);

	for (int i = startpos + 1; i <= B.size() - A.size(); i++) {
		tmp = 0;
		for (int j = 0; j < A.size(); j++) {
			tmp += A[j] * B[i + j];
		}
		sum = max(sum, tmp);
	}

	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, M;
		int sum = 0;

		cin >> N >> M;

		vector<int> A;
		vector<int> B;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;
			A.push_back(n);
		}
		for (int i = 0; i < M; i++) {
			int n;
			cin >> n;
			B.push_back(n);
		}

		if (N == M) {
			for (int i = 0; i < N; i++) {
				sum += A[i] * B[i];
			}
		}
		else if (N < M) {
			sum = maxline(A, B);
		}
		else if (N > M) {
			sum = maxline(B, A);
		}

		cout << "#" << t << " " << sum << "\n";
	}

	return 0;
}