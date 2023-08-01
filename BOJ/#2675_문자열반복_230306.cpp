#include<iostream>
#include<string>
using namespace std;
int main() {
	int N, count;
	cin >> N;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> count >> str;
		for (int j = 0; j < str.length(); j++) {
			for (int k = 0; k < count; k++)
				cout << str[j];
		}
		cout << '\n';
	}
	return 0;
}