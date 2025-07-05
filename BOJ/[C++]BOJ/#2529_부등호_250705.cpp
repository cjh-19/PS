#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int K;
vector<char> signList;
vector<string> numList; // 가능한 정수 리스트(문자열로 표현)의 묶음

void dfs(int cnt, string num, vector<bool> visited) {
	if (cnt == signList.size() + 1) {
		numList.push_back(num);
		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (!visited[i]) {
			// signList에 대해서 num이 만족하는지 체크
			if (cnt >= 1) {
				if (signList[cnt - 1] == '<') {
					if (num[cnt - 1] - '0' >= i) continue;
				}
				else if (signList[cnt - 1] == '>') {
					if (num[cnt - 1] - '0' <= i) continue;
				}
			}
			visited[i] = true;
			dfs(cnt + 1, num + to_string(i), visited);
			visited[i] = false;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);

	cin >> K;
	for (int i = 0; i < K; i++) {
		char c;
		cin >> c;
		signList.push_back(c);
	}

	vector<bool> visited(10); // 0~9까지 사용 숫자
	dfs(0, "", visited);

	sort(numList.begin(), numList.end());

	cout << numList[numList.size() - 1] << "\n" << numList[0];

	return 0;
}