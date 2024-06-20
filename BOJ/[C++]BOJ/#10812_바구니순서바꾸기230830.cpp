#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, begin, mid, end;
	cin >> N >> M;
	int num[101] = { 0, };
	for (int i = 1; i <= N; i++)
		num[i]=i;
	for (int i = 0; i < M; i++) {
		cin >> begin >> end >> mid;
		int tmp[100] = { 0, };
		for (int j = 1; j <= N; j++)
			tmp[j] = num[j];
		for (int j = 0; j <= end - mid; j++)
			num[begin + j] = tmp[mid + j];
		for (int j = 0; j < mid - begin; j++)
			num[begin + end - mid + 1+j] = tmp[begin + j];
	}
	for (int i = 1; i <= N; i++)
		cout << num[i] << " ";
	return 0;
}