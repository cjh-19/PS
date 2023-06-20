#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, sum = 1, i, count;
	cin >> N;
	for (i = 0; i <	N; sum++)
		i += sum;
	sum -= 1;
	if (sum % 2 == 0) {
		count = i - N;
		cout << sum - count << "/" << count + 1;
	}
	else if (sum % 2 == 1) {
		count = i - N;
		cout << count + 1 << "/" << sum - count;
	}

	return 0;
}