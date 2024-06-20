#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int Num;
	cin >> Num;
	cin.ignore(); // 버퍼 비우기
	string str;
	stack<char> st;
	for (int i = 0; i < Num; i++) {
		getline(cin, str);
		for (int j = 0; j <= str.length(); j++) {
			if (str[j] == ' ' || str[j] == '\0') {
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << ' ';
			}
			else
				st.push(str[j]);
		}
		cout << "\n";
	}

	return 0;
}