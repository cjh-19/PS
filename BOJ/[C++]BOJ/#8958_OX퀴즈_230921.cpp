#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		int sum = 0, count = 0;
		for (int j = 0; j < str.length(); j++) {
			if (str.substr(j, 1) == "O") {
				count++;
				sum += count;
			}
			else if (str.substr(j, 1) == "X") {
				count = 0;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}