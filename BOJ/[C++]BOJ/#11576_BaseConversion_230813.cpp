#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int A, B, num, sum = 0;
	cin >> A >> B >> num;
	stack<int> st;
	for (int i = 0; i < num; i++) {
		int N;
		cin >> N;
		sum += N * pow(A, num - i - 1);
	}
	while (1) {
		st.push(sum % B);
		sum /= B;
		if (sum == 0)
			break;
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}

	return 0;
}