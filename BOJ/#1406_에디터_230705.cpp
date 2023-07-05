#include<iostream>
#include<string>
#include<list>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	list<char> Li;
	list<char>::iterator iter = Li.end();
	string str;
	int num;
	char input;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		Li.push_back(str[i]);
	}
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> input;
		if (input == 'L') {
			if(iter != Li.begin())
				iter--;
		}
		else if (input == 'D') {
			if(iter != Li.end())
				iter++;
		}
		else if (input == 'B') {
			if (iter != Li.begin()) {
				iter--;
				iter = Li.erase(iter);
			}
		}
		else if (input == 'P') {
			char add;
			cin >> add;
			Li.insert(iter, add);
		}
	}
	for (iter = Li.begin(); iter != Li.end(); iter++)
		cout << *iter;
	cout << "\n";
	return 0;
}