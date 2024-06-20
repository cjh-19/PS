#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[9][9], max = -1, Xm, Ym;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (max < arr[i][j]) {
				max = arr[i][j];
				Xm = i + 1, Ym = j + 1;
			}
		}
	}
	cout << max << "\n" << Xm << " " << Ym;
	return 0;
}