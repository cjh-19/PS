#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

// NUMEROUS를 넘어가도 저장하므로 INT_MAX범위보다 크게 잡음
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

// 2^32-1 까지 체크
int MAX_INT = 0x7fffffff;
int ZERO = 62625;

// 집합을 출력하는 함수
int print(const vector<int>& vec) {
	cout << '{';
	for (int i = 0, len = vec.size(); i < len; i++) {
		cout << vec[i];
		if (i != len - 1)cout << ",";
	}
	cout << '}';

	return 0;
}

int main() {
	// 코드의 속도를 더 빠르게 하기 위한 작업
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
		// 이 범위를 벗어나면 출력을 하지 않음
		if (sum > ZERO * 2 || sum < -ZERO * 2 || n <= 0 || n > 500) continue;

		// 원소를 오름차순으로 저장하기 위해 내림차순으로 정렬
		sort(nums, nums + n, greater<int>());
		// dp 배열 0으로 초기화
		memset(dp, 0, sizeof(dp));

		// 아무 숫자도 안쓰는 경우
		dp[0][ZERO] = 1;
		// 첫번째 숫자를 쓰는 경우
		dp[0][ZERO + nums[0]] = 1;

		for (int i = 1; i < n; i++) {

			int tnum = nums[i];

			for (int j = 0; j <= 62625 * 2; j++) {

				// j - tnum이 0보다 클 때
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

			// 32bit 정수형을 초과하는 경우
			// "NUMEROUS" 출력
			if (ans > MAX_INT) {
				cout << "NUMEROUS\n";
			}
			else cout << ans << "\n";
		}
		else {
			// 절반 크기의 합이 없는 경우
			cout << 0 << "\n";

			// 그나마 제일 큰 부분합 찾기
			// 마지막 원소가 담겼을 때의 합을 찾기
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

			// tsum - tnum이 0보다 크고
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

		// 집합을 오름차순으로 출력
		if (set1.size() == n || set2.size() == n) {
			print(set1);
			cout << ',';
			print(set2);
		}
		else if (set1[0] < set2[0]) {
			print(set1);
			cout << ',';
			print(set2);
		}
		else {
			print(set2);
			cout << ',';
			print(set1);
		}
		cout << "\n";
	}

	return 0;
}