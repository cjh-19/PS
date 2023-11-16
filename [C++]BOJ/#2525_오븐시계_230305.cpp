#include<iostream>
using namespace std;
int main() {
	int H, M, Time;
	cin >> H >> M >> Time;
	if (H + (M + Time) / 60 >= 24) {
		H = H + (M + Time) / 60 - 24;
		M = (M + Time) % 60;
	}
	else {
		H = H + (M + Time) / 60;
		M = (M + Time) % 60;
	}
	cout << H << " " << M;
	return 0;
}