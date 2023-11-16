#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int X, Y, num = 0, sum = 0;
	int arr[1] = {0};
	cin >> X >> Y;
	for (int i = X; i <= Y; i++) {
		int count = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				count++;
		}
		if (count == 2) {
			if (num == 0) {
				arr[num] = i;
				num++;
			}
			sum += i;
		}
	}
	if (num != 0) {
		cout << sum << "\n" << arr[0];
	}
	else
		cout << -1;
	return 0;
}