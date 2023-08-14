#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Num, count = 0;
	cin >> Num;
	while (Num != 1) {
		if (Num % 3 == 0)
			Num /= 3;
		else if ((Num - 1) % 3 == 0)
			Num -= 1;
		else if (Num % 2 == 0)
			Num /= 2;
		else
			Num -= 1;
		count++;
	}
	cout << count << "\n";

	return 0;
}