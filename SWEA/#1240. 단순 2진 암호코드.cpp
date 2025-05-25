#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;

void init() {
	um.insert({ "0001101", 0 });
	um.insert({ "0011001", 1 });
	um.insert({ "0010011", 2 });
	um.insert({ "0111101", 3 });
	um.insert({ "0100011", 4 });
	um.insert({ "0110001", 5 });
	um.insert({ "0101111", 6 });
	um.insert({ "0111011", 7 });
	um.insert({ "0110111", 8 });
	um.insert({ "0001011", 9 });
}

int check(string enc) {
	vector<int> v;
	for (int i = 0; i < 8; i++) {
		string str = enc.substr(i * 7, 7);
		v.push_back(um[str]);
	}

	int sum = 0;
	int chkSum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		if (i % 2 == 0) {
			chkSum += v[i] * 3;
		}
		else {
			chkSum += v[i];
		}
	}

	if (chkSum % 10 == 0) {
		return sum;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	init();

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N, M;
		cin >> N >> M;
		string encrypt;
		int lastIdx = 0;
		bool chk = false;
		for (int j = 0; j < N; j++) {
			string str;
			cin >> str;
			if (!chk) {
				for (int k = 0; k < str.length(); k++) {
					if (str[k] == '1') {
						lastIdx = k;
						chk = true;
						encrypt = str;
					}
				}
			}
		}

		encrypt = encrypt.substr(lastIdx - 55, 56);

		cout << "#" << i << " " << check(encrypt) << "\n";
	}

	return 0;
}