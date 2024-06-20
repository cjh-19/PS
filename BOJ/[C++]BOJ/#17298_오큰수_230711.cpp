#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int Num, N;
	cin >> Num;
	vector<int> vt;
	stack<int> st, result;
	for (int i = 0; i < Num; i++) {
		cin >> N;
		vt.push_back(N);
	}
	for (int i = Num - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= vt[i])
			st.pop();
		if (st.empty())
			result.push(-1);
		else
			result.push(st.top());
		st.push(vt[i]);
	}
	while (!result.empty()) {
		cout << result.top() << ' ';
		result.pop();
	}
	cout << "\n";

	return 0;
}