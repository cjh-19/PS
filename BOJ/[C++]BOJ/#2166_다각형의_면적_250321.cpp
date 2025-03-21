#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<long, long>> v;

// 면적 구하기
double area() {
	double value = 0.0;
	for (int i = 0; i < N; i++) {
		// (x1 * y2 - x2 * y1) 로 시작해서 (xN * y1 - x1 * yN) 까지
		value += (v[i].first * v[i + 1].second - v[i + 1].first * v[i].second);
	}

	return abs(value) / 2.0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	v.push_back({ v[0] }); // 시작 지점 추가

	// 소수점 둘째자리에서 반올림
	// 소수점 첫째자리까지는 무조건 출력
	cout << fixed;
	cout.precision(1);
	cout << area();

	return 0;
}