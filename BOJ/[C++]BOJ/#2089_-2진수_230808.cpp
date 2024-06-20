#include<iostream>
#include<cmath>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Num;
	cin >> Num;
	stack<int> result;
	if (Num == 0) {
		cout << "0\n";
		return 0;
	}
	while (Num != 0) {
		if (Num % -2 == 0) {
			result.push(0);
			Num /= -2;
		}
		else {
			result.push(1);
			Num = (Num - 1) / -2;
		}
	}
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}
	cout << "\n";

	return 0;
}