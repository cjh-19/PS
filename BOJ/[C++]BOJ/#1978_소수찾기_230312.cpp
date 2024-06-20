#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, Frq = 0;
	cin >> T;
	for(int i=0; i<T; i++) {
		int Num;
		cin >> Num;
		int count = 0;
		if (Num > 1) {
			for (int j = 2; j <= Num; j++) {
				if (Num % j == 0) {
					count++;
				}
			}
		}
		if (count == 1)
			Frq++;
	}
	cout << Frq;
	return 0;
}