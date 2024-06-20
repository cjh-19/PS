#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned long long n;
	cin >> n;
	cout << n * (n - 1) * (n - 2) / 6 << "\n" << 3;
	return 0;
}