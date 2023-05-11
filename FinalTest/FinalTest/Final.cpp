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
// 합의 최소 값인 -125,250의 절반 부터
// 합의 최대 값인 125,250의 절반의 경우의 수만 구하면 됨

// dp[i][j] i번째 까지 갔을 때
// 수의 합이 j가 나오는 경우의 수
// 이 때 음수 합을 인덱스로 쓰기 위해 62625를 더해 줌
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
		// -125,250 <= sum <= 125,250 이고 1 <= n <= 500
		// 이 범위를 벗어나면 출력을 하지 않음, 이 if문을 넣을지 말지 고민
		if (sum > ZERO * 2 || sum < -ZERO * 2 || n <= 0) continue;

		// 입력받은 값 정렬
		sort(nums, nums + n);
		// dp 배열 0으로 초기화
		memset(dp, 0, sizeof(dp));

		// 아무 숫자도 안쓰는 경우
		dp[0][ZERO] = 1;
		// 첫번째 숫자를 쓰는 경우
		dp[0][ZERO + nums[0]] = 1;

		for (int i = 1; i < n; i++) {

			int tnum = nums[i];

			for (int j = 0; j <= 62625 * 2; j++) {

				// j - tnum이 -62625보다 클 때
				// tnum을 더하는 경우
				if (j - tnum >= 0) dp[i][j] += dp[i - 1][j - tnum];

				// tnum을 더하지 않는 경우
				dp[i][j] += dp[i - 1][j];
			}
		}

		int max_len = sum / 2 + ZERO;

		// 짝수이면서 값이 존재할 때 
		if (!(sum & 1) && dp[n - 1][max_len]) {

			// 전체 합의 절반은 짝이 서로 같아서
			// 두번 쓰인다 반으로 나눠줌
			// ex) 합이 6 -> 3, 3 = 3에 두번쓰임
			// 6 -> 2,4 = 2랑 4에 한번씩 쓰임
			ll ans = dp[n - 1][max_len] / 2;
			//cout << ans << "\n";

			// 32bit 정수형을 초과하는 경우
			if (ans > MAX_INT) {
				cout << "NUMEROUS\n";// continue;
			}
			else cout << ans << "\n";
		}
		else {
			// 절반 크기의 합이 없는 경우
			cout << 0 << "\n";

			// 그나마 제일 큰 부분합 찾기
			for (int i = max_len; i >= 0; i--) {
				if (dp[n - 1][i]) {
					max_len = i; break;
				}
			}
		}

		vector<int> set1, set2;

		int tsum = max_len;
		// n-1번째 인덱스 부터 1번째 인덱스까지 고려
		for (int i = n - 1; i > 0; i--) {
			int tnum = nums[i];

			// tsum - tnum이 -62625보다 크고
			// dp[i - 1][tsum - tnum]에 값이 있다면
			// tnum을 더해서 tsum을 만들 수 있다는 말
			// 따라서 i번째 수는 max_len을 만드는 데 사용된 수
			if ((tsum - tnum) && dp[i - 1][tsum - tnum]) {
				tsum -= tnum;
				set1.push_back(tnum);
			}
			else set2.push_back(tnum);
		}

		// nums[0]만 고려하면 되는 상태
		// tsum이 0이면 nums[0]이
		// max_len을 만드는데 사용되지 않음
		if (tsum == ZERO) set2.push_back(nums[0]);
		else set1.push_back(nums[0]);

		// 각 집합을 정렬하여 출력
		sort(set1.begin(), set1.end());
		sort(set2.begin(), set2.end());


		// 디버깅용. 제출 시에는 삭제
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