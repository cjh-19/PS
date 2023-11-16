#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int Num, stN, count = 1;
	cin >> Num;
	stack<int> st;
	vector<char> vt;

	for (int i = 0; i < Num; i++) {
		cin >> stN;

		while (count <= stN) {
			st.push(count);
			count++;
			vt.push_back('+');
		}
		if (stN == st.top()) {
			st.pop();
			vt.push_back('-');
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 0; i < vt.size(); i++) {
		cout << vt[i] << "\n";
	}

	return 0;
}