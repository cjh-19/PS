#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x, y;
	cin >> x >> y;
	int n1 = 0, n2 = 0, check = 1;
	while (check <= x || check <= y) {
		if (x % check == 0 && y % check == 0)
			n1 = check;
		check++;
	}
	n2 = x * y / n1;
	cout << n1 << "\n" << n2 << "\n";
	return 0;
}