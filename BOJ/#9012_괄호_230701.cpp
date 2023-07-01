#include<iostream>
#include<stack>

using namespace std;

int main() {
	int Num, check = 0, N = 0;
	cin >> Num;
	string ps;
	stack<char> st;
	while (Num > 0) {
		cin >> ps;
		for (int i = 0; i < ps.length(); i++)
			st.push(ps[i]);
		while (!st.empty()) {
			if (st.top() == '(')
				check--;
			else
				check++;

			if (check < 0)
				N = 1;
			st.pop();
		}
		if (N == 0 && check == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
		check = 0, N = 0;
		Num--;
	}

	return 0;
}