#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, arr[101][101] = { 0 }, count = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		for (int j = x; j < x+10; j++) {
			for (int k = y; k < y+10; k++) {
				if (arr[j][k] == 0) {
					arr[j][k]++;
					count++;
				}
			}
		}
	}
	cout << count;
	return 0;
}