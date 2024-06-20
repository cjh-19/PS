#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int time[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	string num;
	cin >> num;
	int T=0;
	for (int i = 0; i < num.length(); i++) {
		T += time[num[i] - 'A'];
	}
	cout << T;
	return 0;
}