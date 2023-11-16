#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, arr[100] = { 0, };
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		arr[i] = i;
	}
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		int tmp = arr[x];
		arr[x] = arr[y];
		arr[y] = tmp;
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}