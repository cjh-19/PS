#include<iostream>

using namespace std;

int arr[1000000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N1, N2;
	cin >> N1 >> N2;

	for (int i = 2; i <= N2; i++)
		arr[i] = i;
	for (int i = 2; i * i <= N2; i++) {
		if (arr[i] == 0) continue;
		for (int j = 2 * i; j <= N2; j+=i)
			arr[j] = 0;
	}
	for (int i = N1; i <= N2; i++) {
		if (arr[i] != 0)
			cout << i << "\n";
	}

	return 0;
}