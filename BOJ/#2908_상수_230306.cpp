#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str1, str2;
	int s1=0, s2=0;
	cin >> str1 >> str2;
	for (int i = 1; i <= 3; i++) {
		int num = 1;
		for (int j = 0; j < i; j++) {
			if (j != 0)
				num *= 10;
		}
		s1 += (str1[i-1]-48)*num;
		s2 += (str2[i-1]-48)*num;
	}
	if (s1 < s2)
		cout << s2;
	else
		cout << s1;
	return 0;
}