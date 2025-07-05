#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
// 1. 자릿수가 가장 높으면 높은 숫자 할당
// 2. 자릿수가 같은 알파벳은 다시 사용될 때
// 자릿수가 더 높은 알파벳에게 높은 숫자 할당
vector<pair<int, char>> numPriority; // <자릿수, 알파벳>
unordered_map<char, int> enNum;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			enNum[str[j]] += pow(10, str.length() - 1 - j);
		}
	}

	for (auto m : enNum) {
		numPriority.push_back({ m.second, m.first });
	}

	sort(numPriority.rbegin(), numPriority.rend());

	long long sum = 0;
	for (int i = 0; i < numPriority.size(); i++) {
		sum += numPriority[i].first * (9 - i);
	}

	cout << sum;

	return 0;
}