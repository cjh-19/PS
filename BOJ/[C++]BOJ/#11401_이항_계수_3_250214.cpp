#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, K;
ll mod = 1000000007;

// s ���丮�� ����, e ���丮�� ��
ll factorial(int s, int e) {
	ll res = 1;
	for (int i = s; i >= e; i--) {
		res = res * i % mod;
	}
	return res;
}

// num : ��, p : ����
// p�� 10���̱� ������ ���������� Ǯ�� 1�ʾȿ� ���� x
// ���� ���� �������� �ذ� -> ��� (O(logn))
ll power(ll num, ll p) {
	if (p == 0) return 1;
	// ���� ���� ���
	ll res = power(num, p / 2);
	res = res * res % mod;
	// p ������ Ȧ���� ��� num�� �ѹ� �� �����ָ� �� -> ex) p=5: 5/2 = 2 �̹Ƿ� num^4�� ���Ǳ� ����
	if (p % 2 == 1) res = res * num % mod;
	return res;
}

int main() {
	ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	// n���� n-k+1���� ���丮�� + k�� mod-2 �ŵ�����
	ll result = factorial(N, N - K + 1) * power(factorial(K, 1), mod - 2) % mod;
	cout << result;

	return 0;
}