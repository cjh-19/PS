#include<iostream>
#include<algorithm>

#define MAX 100001

using namespace std;

int N;
int dp[MAX];

void solve() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = i; //초기화 : 전부다 1의 제곱으로 나타냈을 경우
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

// N에서 i의 제곱을 뺐을 때 0이 되지 않는 선에서
// 나올 수 있는 모든 개수 중 최소(min)가 되는 값 구하기
// dp[a] = b => a라는 숫자를 제곱수의 합으로 나타낼 수 있는 최소항의 갯수는 b개
// dp[i] = min( dp[i], dp[i - j * j] + 1)
// +1 이유 : dp[i - j * j]에서 제곱수를 한번 썼기 때문
// ex) dp[5] = dp[5-1*1]+1 : dp[4]인 경우에 1을 제곱한 값을 더한 경우
// dp[5] = dp[5-2*2]+1 : dp[1]인 경우에 2을 제곱한 값을 더한 경우