#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; // 수열의 크기
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		// lower_bound를 통해 v.begin() 부터 v.end() 사이에 num 이상의 값이 등장하는 첫번째 포인터를 구함
		auto it = lower_bound(v.begin(), v.end(), num);
		if (it == v.end()) v.push_back(num); // 최댓값이면 추가
		else *it = num; // lower_bound 포인터에 num 값을 대체
	}

	cout << v.size() << "\n";

	return 0;
}