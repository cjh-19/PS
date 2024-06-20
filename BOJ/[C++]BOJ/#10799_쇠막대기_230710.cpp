#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	string str;
	cin >> str;
	queue<char> Q;
	int bar = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(')
			Q.push(str[i]);
		else if (str[i] == ')' && str[i - 1] == '(') {
			Q.pop();
			bar += Q.size();
		}
		else if (str[i] == ')' && str[i - 1] == ')') {
			bar += 1;
			Q.pop();
		}
	}
	cout << bar << "\n";

	return 0;
}