#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		int Num;
		cin >> Num;
		int arr[100001] = { 0, }, Frq = 0, sum = 0;
		for (int i = 1; i <= Num; i++) {
			if (Num % i == 0) {
				arr[Frq] = i;
				sum += i;
				Frq++;
			}
		}
		sum -= Num;
		if (sum == Num) {
			int t = 0;
			cout << Num << " = ";
			while (1) {
				cout << arr[t];
				if (t == Frq - 2)
					break;
				cout << " + ";
				t++;
			}
		}
		else if (sum != Num && Num > 0)
			cout << Num << " is NOT perfect.";
		else if (Num == -1)
			break;
		cout << "\n";
	}

	return 0;
}