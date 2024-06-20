#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	queue<char> Q;
	stack<double> st;
	vector<int> vt;
	string str;
	int Num, N;
	double result;
	cin >> Num;
	cin >> str;
	for (int i = 0; i < Num; i++) {
		cin >> N;
		vt.push_back(N);
	}
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 65 && str[i] <= 90) {
			Q.push(vt[str[i] - 65] + '0');
		}
		else
			Q.push(str[i]);
	}
	while (!Q.empty()) {
		if (Q.front() != '*' && Q.front() != '/' && Q.front() != '-' && Q.front() != '+') {
			st.push(Q.front() - '0');
			Q.pop();
		}
		else {
			if (Q.front() == '+') {
				double A = st.top();
				st.pop();
				double B = st.top();
				st.pop();
				st.push(B + A);
				Q.pop();
			}
			else if (Q.front() == '-') {
				double A = st.top();
				st.pop();
				double B = st.top();
				st.pop();
				st.push(B - A);
				Q.pop();
			}
			else if (Q.front() == '*') {
				double A = st.top();
				st.pop();
				double B = st.top();
				st.pop();
				st.push(B * A);
				Q.pop();
			}
			else if (Q.front() == '/') {
				double A = st.top();
				st.pop();
				double B = st.top();
				st.pop();
				st.push(B / A);
				Q.pop();
			}
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << st.top() << "\n";
	st.pop();
	return 0;
}