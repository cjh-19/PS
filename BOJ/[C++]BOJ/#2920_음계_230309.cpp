#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[8] = { 0 }, cr = 0, dcr = 0;
	for (int i = 0; i < 8; i++)
		cin >> arr[i];
	for (int i = 0; i < 8; i++) {
		if (arr[i] == i + 1)
			cr++;
		else if (arr[i] == 8 - i)
			dcr++;
	}
	if (cr == 8)
		cout << "ascending";
	else if (dcr == 8)
		cout << "descending";
	else
		cout << "mixed";
	return 0;
}