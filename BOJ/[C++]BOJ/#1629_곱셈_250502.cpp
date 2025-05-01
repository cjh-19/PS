#include <iostream>

using namespace std;

typedef long long ll;

ll A, B, C;

ll multiple(ll B) {
	if (B == 0) return 1;

	ll half = multiple(B / 2);
	ll result = half * half % C;

	// 홀수인 경우
	if (B % 2 == 1) result = result * A % C;
	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> A >> B >> C;
	cout << multiple(B);

	return 0;
}