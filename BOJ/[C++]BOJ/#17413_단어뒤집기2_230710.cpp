#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int check = 0;
	string str;
	stack<char> st;
	getline(cin, str);
	for (int i = 0; i <= str.length(); i++) {
		if (!st.empty() && (str[i] == '<' || str[i] == ' ' || str[i] == '\0')) {
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
			if (str[i] == '<') {
				cout << str[i];
				check = 1;
			}
			else
				cout << ' ';
		}
		else {
			if (str[i] == '<')
				check = 1;
			if (check == 0)
				st.push(str[i]);
			else if (check == 1) {
				cout << str[i];
				if (str[i] == '>')
					check = 0;
			}
		}
	}
	cout << "\n";

	return 0;
}