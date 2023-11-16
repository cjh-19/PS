#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	int arr[26] = { 0, }, max = 0,min=0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 97)
			str[i] -= 32;
		arr[str[i] - 65]++;
	}
	char X;
	for (int i = 0; i < 26; i++) {
		if (max < arr[i]) {
			max = arr[i];
			X = 'A';
			X += i;
		}
		else if (max > 0 && max == arr[i])
			min = max;
	}
	if (min == max)
		cout << '?';
	else
		cout << X;
	return 0;
}