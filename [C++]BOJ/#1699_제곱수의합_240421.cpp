#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int dp[100001];
	// �ʱ�ȭ
	for (int i = 0; i <= N; i++) {
		dp[i] = i;
	}
	for (int i = 1; i <= N; i++) {

	}


	return 0;
}

// N���� i�� ������ ���� �� 0�� ���� �ʴ� ������
// ���� �� �ִ� ��� ���� �� �ּ�(min)�� �Ǵ� �� ���ϱ�
// d[i] = min( d[i], d[i - j * j] + 1) // +1 ���� : d[i - j * j]���� �������� �ѹ� ��� ���� 