#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int NUM, sum = 0, K;
	cin >> NUM;
	vector<int>arr;
	int plus[4001] = { 0 }, minus[4001] = { 0 }, MaxK = 0, MinK = 0;
	for (int i = 0; i < NUM; i++) {
		cin >> K;
		arr.push_back(K);
		sum += K;
		if (K >= 0)
			plus[arr[i]]++;
		else if (K < 0)
			minus[-1 * arr[i]]++;

		if (i == 0)
			MaxK = K, MinK = K;
		else if (K > MaxK)
			MaxK = K;
		else if (K < MinK)
			MinK = K;
	}
	sort(arr.begin(), arr.end());
	int count = 1, two = 0, num = 0, maxc = 0;
	if (NUM == 1)
		num = arr[0];
	else {
		for (int i = 0; i < NUM - 1; i++) {
			if (arr[i] == arr[i + 1]) {
				count++;
			}
			else if (arr[i] != arr[i + 1]) {
				if (count > maxc) {
					maxc = count;
					num = arr[i];
					two = 0;
				}
				else if (count == maxc && two == 0) {
					num = arr[i];
					two = 1;
				}
				count = 1;
			}
			if (i == NUM - 2 && count == maxc && two == 0)
				num = arr[i];
			else if (i == NUM - 2 && count > maxc)
				num = arr[i];
		}
	}
	double avg = floor((double)sum / NUM + 0.5);
	cout << avg << "\n" << arr[NUM / 2] << "\n" << num << "\n" << MaxK - MinK << "\n";

	return 0;
}