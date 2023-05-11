#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

int n;

int nums[500];

// 500 * 501 / 2 / 2 = 62625
// ���� �ּ� ���� -125,250�� ���� ����
// ���� �ִ� ���� 125,250�� ������ ����� ���� ���ϸ� ��

// dp[i][j] i��° ���� ���� ��
// ���� ���� j�� ������ ����� ��
// �� �� ���� ���� �ε����� ���� ���� 62625�� ���� ��
ll dp[500][62625 * 2 + 10];

int MAX_INT = 0x7fffffff;
int ZERO = 62625;

int print(const vector<int>& vec) {
	int sum = 0;

	cout << '{';
	for (int i = 0, len = vec.size(); i < len; i++) {
		sum += vec[i];
		cout << vec[i];
		if (i != len - 1)cout << ", ";
	}
	cout << '}';

	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while (true) {
		string chk;
		cin >> chk;
		if (chk == "EOI") break;

		n = stoi(chk);

		int sum = 0;

		for (int i = 0; i < n; i++) {
			cin >> nums[i];
			sum += nums[i];
		}
		// -125,250 <= sum <= 125,250 �̰� 1 <= n <= 500
		// �� ������ ����� ����� ���� ����, �� if���� ������ ���� ���
		if (sum > ZERO * 2 || sum < -ZERO * 2 || n <= 0) continue;

		// �Է¹��� �� ����
		sort(nums, nums + n);
		// dp �迭 0���� �ʱ�ȭ
		memset(dp, 0, sizeof(dp));

		// �ƹ� ���ڵ� �Ⱦ��� ���
		dp[0][ZERO] = 1;
		// ù��° ���ڸ� ���� ���
		dp[0][ZERO + nums[0]] = 1;

		for (int i = 1; i < n; i++) {

			int tnum = nums[i];

			for (int j = 0; j <= 62625 * 2; j++) {

				// j - tnum�� -62625���� Ŭ ��
				// tnum�� ���ϴ� ���
				if (j - tnum >= 0) dp[i][j] += dp[i - 1][j - tnum];

				// tnum�� ������ �ʴ� ���
				dp[i][j] += dp[i - 1][j];
			}
		}

		int max_len = sum / 2 + ZERO;

		// ¦���̸鼭 ���� ������ �� 
		if (!(sum & 1) && dp[n - 1][max_len]) {

			// ��ü ���� ������ ¦�� ���� ���Ƽ�
			// �ι� ���δ� ������ ������
			// ex) ���� 6 -> 3, 3 = 3�� �ι�����
			// 6 -> 2,4 = 2�� 4�� �ѹ��� ����
			ll ans = dp[n - 1][max_len] / 2;
			//cout << ans << "\n";

			// 32bit �������� �ʰ��ϴ� ���
			if (ans > MAX_INT) {
				cout << "NUMEROUS\n";// continue;
			}
			else cout << ans << "\n";
		}
		else {
			// ���� ũ���� ���� ���� ���
			cout << 0 << "\n";

			// �׳��� ���� ū �κ��� ã��
			for (int i = max_len; i >= 0; i--) {
				if (dp[n - 1][i]) {
					max_len = i; break;
				}
			}
		}

		vector<int> set1, set2;

		int tsum = max_len;
		// n-1��° �ε��� ���� 1��° �ε������� ���
		for (int i = n - 1; i > 0; i--) {
			int tnum = nums[i];

			// tsum - tnum�� -62625���� ũ��
			// dp[i - 1][tsum - tnum]�� ���� �ִٸ�
			// tnum�� ���ؼ� tsum�� ���� �� �ִٴ� ��
			// ���� i��° ���� max_len�� ����� �� ���� ��
			if ((tsum - tnum) && dp[i - 1][tsum - tnum]) {
				tsum -= tnum;
				set1.push_back(tnum);
			}
			else set2.push_back(tnum);
		}

		// nums[0]�� ����ϸ� �Ǵ� ����
		// tsum�� 0�̸� nums[0]��
		// max_len�� ����µ� ������ ����
		if (tsum == ZERO) set2.push_back(nums[0]);
		else set1.push_back(nums[0]);

		// �� ������ �����Ͽ� ���
		sort(set1.begin(), set1.end());
		sort(set2.begin(), set2.end());


		// ������. ���� �ÿ��� ����
		// cout << sumA << "/" << sumB;
		int sumA = 0, sumB = 0;
		if (set1.size() == n || set2.size() == n) {
			sumA = print(set1);
			cout << ',';
			sumB = print(set2);
			cout << sumA << "/" << sumB;
		}
		else if (set1[0] < set2[0]) {
			sumA = print(set1);
			cout << ',';
			sumB = print(set2);
			cout << sumA << "/" << sumB;
		}
		else {
			sumB = print(set2);
			cout << ',';
			sumA = print(set1);
			cout << sumB << "/" << sumA;
		}



		cout << "\n";
	}
}