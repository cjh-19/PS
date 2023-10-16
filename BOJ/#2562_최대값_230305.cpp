#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[9], max = 0, num;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if (max < arr[i]) {
			max = arr[i];
			num = i + 1;
		}
	}
	cout << max << "\n" << num;
	return 0;
}