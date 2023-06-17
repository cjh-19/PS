#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Up, Down, V;
	cin >> Up >> Down >> V;
	if ((V - Up) % (Up - Down) == 0)
		cout << (V - Up) / (Up - Down) + 1;
	else if ((V - Up) % (Up - Down) != 0)
		cout << (V - Up) / (Up - Down) + 2;

	return 0;
}