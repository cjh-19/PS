#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[5], avg = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		avg += arr[i];
	}
	for (int i = 0; i < 5; i++) {
		int tmp = arr[i];
		for (int j = i+1; j < 5; j++) {
			if (tmp > arr[j]) {
				arr[i] = arr[j];
				arr[j] = tmp;
				tmp = arr[i];
			}
		}
	}
	cout << avg/5 << "\n" << arr[2] << "\n";
	return 0;
}