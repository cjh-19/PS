#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[1230] = { 0, }, num = 0;

	for (int i = 2; i <= 10000; i++) {
		int count = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0)
				count++;
		}
		if (count == 2) {
			arr[num] = i;
			num++;
		}
	}

	int T, Num;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> Num;
		int Frq = 0, tmp1 = 0, tmp2 = 0;
		for(int k=0; k<num; k++) {
			for (int j = Frq; j < num; j++) {
				if ((Num - arr[Frq]) == arr[j]) {
					tmp1 = arr[Frq], tmp2 = arr[j];
					break;
				}
			}
			Frq++;
		}
		cout << tmp1 << " " << tmp2 << "\n";
	}

	return 0;
}