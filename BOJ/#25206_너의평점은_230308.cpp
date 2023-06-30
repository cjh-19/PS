#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string arr[20][2];
	double avg = 0, count = 0, sum = 0;
	for (int i = 0; i < 20; i++) {
		cin >> arr[i][0];
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
		if (arr[i][1] == "A+") {
			avg += stod(arr[i][0]) * 4.5;
			count++;
			sum += stod(arr[i][0]);
		}
		else if (arr[i][1] == "A0") {
			avg += stod(arr[i][0]) * 4.0;
			count++;
			sum += stod(arr[i][0]);
		}
		else if (arr[i][1] == "B+") {
			avg += stod(arr[i][0]) * 3.5;
			count++;
			sum += stod(arr[i][0]);
		}
		else if (arr[i][1] == "B0") {
			avg += stod(arr[i][0]) * 3.0;
			count++;
			sum += stod(arr[i][0]);
		}
		else if (arr[i][1] == "C+") {
			avg += stod(arr[i][0]) * 2.5;
			count++;
			sum += stod(arr[i][0]);
		}
		else if (arr[i][1] == "C0") {
			avg += stod(arr[i][0]) * 2.0;
			count++;
			sum += stod(arr[i][0]);
		}
		else if (arr[i][1] == "D+") {
			avg += stod(arr[i][0]) * 1.5;
			count++;
			sum += stod(arr[i][0]);
		}
		else if (arr[i][1] == "D0") {
			avg += stod(arr[i][0]) * 1.0;
			count++;
			sum += stod(arr[i][0]);
		}
		else if (arr[i][1] == "F") {
			avg += stod(arr[i][0]) * 0;
			count++;
			sum += stod(arr[i][0]);
		}
	}
	cout << fixed;
	cout.precision(6);
	cout << avg / sum;
	return 0;
}