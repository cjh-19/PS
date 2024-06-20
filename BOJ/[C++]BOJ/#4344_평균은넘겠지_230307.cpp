#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int avg=0;
		int score[1000] = { 0, };
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> score[j];
			avg += score[j];
		}
		avg = avg / num;
		int count = 0;
		for (int j = 0; j < num; j++) {
			if (score[j] > avg)
				count++;
		}
		cout << fixed;
		cout.precision(3);
		cout << (double)count*100 / (double)num << "%\n";
	}
	return 0;
}