#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Num, n = 2;
	cin >> Num;
	if (Num == 1)
		return 0;
	while (Num != 1) {
		if (Num % n == 0) {
			cout << n << "\n";
			Num = Num / n;
		}
		else if (Num % n != 0)
			n++;
	}

	return 0;
}