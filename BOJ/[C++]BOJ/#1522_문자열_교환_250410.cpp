#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	int aCnt = 0;
	int bCnt = 0;
	int minB = INT_MAX;

	// a의 개수 확인
	for (char c : str) {
		if (c == 'a') aCnt++;
	}

	int len = str.length();
	str += str; // 원형

	// 첫 시작은 초기 값 세팅
	for (int j = 0; j < aCnt; j++) {
		if (str[j] == 'b') bCnt++; //  b 개수 세기
	}
	minB = min(minB, bCnt);

	// a의 길이만큼 슬라이딩 하며 b의 개수가 최소가 될 때
	// 시작점이 맨 끝 문자가 될 때까지 반복
	for (int i = 1; i < len; i++) {

		// 슬라이딩 윈도우
		if (str[i - 1] == 'b') bCnt--;
		if (str[i + aCnt - 1] == 'b') bCnt++;

		minB = min(minB, bCnt);
	}

	cout << minB;

	return 0;
}