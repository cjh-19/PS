#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int NUM;
	cin >> NUM;
	int arr[10001] = { 0 }, count = 0;
	for (int i = 0; i < NUM; i++) {
		cin >> count;
		arr[count]++;
	}
	for (int i = 1; i <= 10000; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}
	return 0;
}