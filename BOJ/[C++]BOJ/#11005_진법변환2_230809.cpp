#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Num, B;
	cin >> Num >> B;
	stack<char> st;
	while (Num != 0) {
		int n = Num % B;
		if (n >= 0 && n <= 9)
			st.push(n + '0');
		else
			st.push(n - 10 + 'A');
		Num /= B;
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	cout << "\n";
	return 0;
}