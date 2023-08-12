#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int num[42] = { 0, }, N;
	for (int i = 0; i < 10; i++) {
		cin >> N;
		num[N % 42] = 1;
	}
	int count = 0;
	for (int i = 0; i < 42; i++) {
		if (num[i] == 1)
			count++;
	}
	cout << count;
	return 0;
}