#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str = to_string(i);
		int cnt = 0;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '3' || str[j] == '6' || str[j] == '9') {
				cnt++;
			}
		}
		if (cnt > 0) {
			for (int j = 0; j < cnt; j++) {
				cout << "-";
			}
		}
		else {
			cout << str;
		}
		if (i < N) cout << " ";
	}

	return 0;
}