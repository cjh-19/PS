#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int Num, Pnum;
	cin >> Num;
	string str;
	deque<int> Dq;
	for (int i = 0; i < Num; i++) {
		cin >> str;
		if (str == "push_front") {
			cin >> Pnum;
			Dq.push_front(Pnum);
		}
		else if (str == "push_back") {
			cin >> Pnum;
			Dq.push_back(Pnum);
		}
		else if (str == "pop_front") {
			if (Dq.empty())
				cout << -1 << "\n";
			else {
				cout << Dq.front() << "\n";
				Dq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (Dq.empty())
				cout << -1 << "\n";
			else {
				cout << Dq.back() << "\n";
				Dq.pop_back();
			}
		}
		else if (str == "size") {
			cout << Dq.size() << "\n";
		}
		else if (str == "empty") {
			if (Dq.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (str == "front") {
			if (Dq.empty())
				cout << -1 << "\n";
			else
				cout << Dq.front() << "\n";
		}
		else if (str == "back") {
			if (Dq.empty())
				cout << -1 << "\n";
			else
				cout << Dq.back() << "\n";
		}
	}

	return 0;
}