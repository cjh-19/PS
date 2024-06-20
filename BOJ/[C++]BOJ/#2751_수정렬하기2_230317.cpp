#include<iostream>
#include<queue>

using namespace std;

queue<int>Q[10];

void sort(int arr[], int MAX, int NUM) {
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
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int NUM, X, MAX1 = 0, MAX2 = 0, n1 = 0, n2 = 0;
	queue<int>Q[10];
	cin >> NUM;
	int* arr = new int[NUM];
	int* arr2 = new int[NUM];
	int* arr3 = new int[NUM];
	for (int i = 0; i < NUM; i++) {
		cin >> X;
		if (X < 0) {
			arr[n1] = -1 * X;
			n1++;
			if (MAX1 < arr[n1-1])
				MAX1 = arr[n1-1];
		}
		else if (X >= 0) {
			arr2[n2] = X;
			n2++;
			if (MAX2 < X)
				MAX2 = X;
		}
	}
	sort(arr, MAX1, n1);
	sort(arr2, MAX2, n2);
	for (int i = 0; i < n1; i++) {
		arr3[i] = -1 * arr[n1 - i - 1];
	}
	for (int i = n1; i < NUM; i++) {
		arr3[i] = arr2[i - n1];
	}
	for (int i = 0; i < NUM; i++) {
		cout << arr3[i] << "\n";
	}
	delete[] arr;
	return 0;
}