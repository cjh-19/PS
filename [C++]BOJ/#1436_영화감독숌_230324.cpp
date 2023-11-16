#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int Num;
	cin >> Num;

	int count = 0, Chk = 666;
	while (count != Num) {
		string str = to_string(Chk);
		for (int i = 0; i < str.length()-2; i++) {
			if (str[i] == '6' && str[i + 1] == '6' && str[i + 2] == '6') {
				count++;
				break;
			}
		}
		if (count == Num)
			break;
		Chk++;
	}
	cout << Chk;
	return 0;
}