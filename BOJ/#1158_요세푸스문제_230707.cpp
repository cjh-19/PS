#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int Num, itv, N;
	cin >> Num >> itv;
	queue<int> Q;
	queue<int> V;
	for (int i = 1; i <= Num; i++)
		Q.push(i);
	while (V.size() != Num) {
		for (int i = 0; i < itv - 1; i++) {
			N = Q.front(); Q.pop(); Q.push(N);
		}
		V.push(Q.front());
		Q.pop();
	}
	cout << "<";
	while (!(V.empty())) {
		cout << V.front();
		if (V.size() != 1)
			cout << ", ";
		V.pop();
	}
	cout << ">\n";

	return 0;
}