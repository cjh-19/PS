#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	int N, M, n1, n2, arr[100] = { 0, };
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		arr[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		int n = (n1 + n2) / 2, num=0;
		for (int j = n1; j <= n; j++) {
			int tmp = arr[j];
			arr[j] = arr[n2 - num];
			arr[n2 - num] = tmp;
			num++;
		}
	}
	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";
	return 0;
}