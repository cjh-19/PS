#include<iostream>
#include<algorithm>

#define MAX 100001

using namespace std;

int N;
int dp[MAX];

void solve() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = i; //�ʱ�ȭ : ���δ� 1�� �������� ��Ÿ���� ���
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[N] << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	solve();

	return 0;
}

// N���� i�� ������ ���� �� 0�� ���� �ʴ� ������
// ���� �� �ִ� ��� ���� �� �ּ�(min)�� �Ǵ� �� ���ϱ�
// dp[a] = b => a��� ���ڸ� �������� ������ ��Ÿ�� �� �ִ� �ּ����� ������ b��
// dp[i] = min( dp[i], dp[i - j * j] + 1)
// +1 ���� : dp[i - j * j]���� �������� �ѹ� ��� ����
// ex) dp[5] = dp[5-1*1]+1 : dp[4]�� ��쿡 1�� ������ ���� ���� ���
// dp[5] = dp[5-2*2]+1 : dp[1]�� ��쿡 2�� ������ ���� ���� ���