#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	int arr[26];
	fill_n(arr, 26, -1);
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		int num = str[i];
		if(arr[num-97] == -1)
			arr[num - 97] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << arr[i] << " ";
	return 0;
}