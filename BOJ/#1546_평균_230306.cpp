#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	double score, arr[1000] = { 0, }, max=0, avg=0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> score;
		arr[i] = score;
		if (max < score)
			max = score;
		avg += score;
	}
	avg = avg / max * 100;
	cout << avg / N;
	return 0;
}