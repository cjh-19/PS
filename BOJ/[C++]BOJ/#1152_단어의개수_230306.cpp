#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	getline(cin, str);
	int num=0;
	if (str[str.length()-1] != ' ')
		num++;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && str[i + 1] == ' ')
			num++;
	}
	cout << num ;
	return 0;
}