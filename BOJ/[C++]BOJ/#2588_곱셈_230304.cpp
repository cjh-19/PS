#include<iostream>
using namespace std;
int main() {
	int A, B, a, b, c;
	cin >> A;
	cin >> B;
	cout << B % 10 * A << endl << B / 10 % 10 * A << endl << B / 100 * A << endl << A * B;
	return 0;
}s