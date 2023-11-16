#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long N;
	cin >> N;
	int i = 1, count = 1;
	while (i < N) {
		i += 6 * count;
		count++;
	}
	cout << count;
	return 0;
}