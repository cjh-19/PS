#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, K;
ll mod = 1000000007;

// s 팩토리얼 시작, e 팩토리얼 끝
ll factorial(int s, int e) {
	ll res = 1;
	for (int i = s; i >= e; i--) {
		res = res * i % mod;
	}
	return res;
}

// num : 밑, p : 지수
// p는 10억이기 때문에 선형적으로 풀면 1초안에 종료 x
// 따라서 분할 정복으로 해결 -> 재귀 (O(logn))
ll power(ll num, ll p) {
	if (p == 0) return 1;
	// 절반 제곱 재귀
	ll res = power(num, p / 2);
	res = res * res % mod;
	// p 지수가 홀수인 경우 num을 한번 더 곱해주면 됨 -> ex) p=5: 5/2 = 2 이므로 num^4만 계산되기 때문
	if (p % 2 == 1) res = res * num % mod;
	return res;
}

int main() {
	ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	// n부터 n-k+1까지 팩토리얼 + k의 mod-2 거듭제곱
	ll result = factorial(N, N - K + 1) * power(factorial(K, 1), mod - 2) % mod;
	cout << result;

	return 0;
}