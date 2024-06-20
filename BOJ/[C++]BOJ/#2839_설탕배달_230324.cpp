#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int Num;
	cin >> Num;
	int x, y, tmp, max=10000;
	for (int i = 0; 5*i <= Num; i++) {
		x = i * 5;
		y = Num - x;
		if (x + y == Num && y % 3 == 0) {
			if (max > (i + (Num - x) / 3))
				max = i + (Num - x) / 3;
		}
	}
	if (max == 10000)
		cout << -1;
	else
		cout << max;
	return 0;
}