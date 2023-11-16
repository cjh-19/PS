#include<iostream>

using namespace std;

#define MAX 1000001
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int num;
	for (int i = 1; i < MAX; i++) arr[i] = i;
	for (int i = 2; i * i < MAX; i++) {
		if (arr[i] == 0) continue;
		for (int j = 2 * i; j < MAX; j += i) {
			arr[j] = 0;
		}
	}
	while (1) {
		cin >> num;
		if (num == 0) break;
		int n1 = 0, n2 = 0;
		for (int i = 2; i < num; i++) {
			if (arr[i] != 0 && arr[num - i] != 0) {
				n1 = arr[i];
				n2 = arr[num - i];
				break;
			}
		}
		if (n1 != 0 && n2 != 0)
			cout << num << " = " << n1 << " + " << n2 << "\n";
		else
			cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}