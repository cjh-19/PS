#include<iostream>
#include<queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int Num, Q;
	cin >> Num;
	queue<int> qu;
	string str;
	for (int i = 0; i < Num; i++) {
		cin >> str;
		if (str == "push") {
			cin >> Q;
			qu.push(Q);
		}
		else if (str == "pop") {
			if (qu.empty())
				cout << -1 << "\n";
			else {
				cout << qu.front() << "\n";
				qu.pop();
			}
		}
		else if (str == "size")
			cout << qu.size() << "\n";
		else if (str == "empty") {
			if (qu.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (str == "front") {
			if (qu.empty())
				cout << -1 << "\n";
			else {
				cout << qu.front() << "\n";
			}
		}
		else if (str == "back") {
			if (qu.empty())
				cout << -1 << "\n";
			else {
				cout << qu.back() << "\n";
			}
		}
	}

	return 0;
}