#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int NUM, CUT, MAX = 0;
	queue<int>Q[10];
	cin >> NUM >> CUT;
	int* arr = new int[NUM];
	for (int i = 0; i < NUM; i++) {
		cin >> arr[i];
		if (MAX < arr[i])
			MAX = arr[i];
	}

	int radix = 1;
	while (1) {
		if (radix >= MAX) break;
		radix = radix * 10;
	}

	for (int i = 1; i <= radix; i = i * 10) {
		for (int j = 0; j < NUM; j++) {
			int k = 0;
			if (arr[j] < i) k = 0;
			else
				k = (arr[j] / i) % 10;
			Q[k].push(arr[j]);
		}

		int tmp = 0;
		for (int j = 0; j < 10; j++) {
			while (Q[j].empty() == 0) {
				arr[tmp] = Q[j].front();
				Q[j].pop();
				tmp++;
			}
		}
	}
	cout << arr[NUM - CUT] << "\n";
	delete[] arr;
	return 0;
}