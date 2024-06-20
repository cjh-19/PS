#include<iostream>
#include<string>
#include<stack>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str;
	cin >> str;
	stack<int> sk;
	for (int i = str.length() - 1; i >= 0; i -= 3) {
		int num = 0, count = 0;
		while (count < 3 && i - count >= 0) {
			if (str[i - count] == '1') {
				num += pow(2, count);
			}
			count++;
		}
		sk.push(num);
	}
	for (int i = 0; sk.size(); i++)
	{
		cout << sk.top();
		sk.pop();
	}
	cout << "\n";
	return 0;
}