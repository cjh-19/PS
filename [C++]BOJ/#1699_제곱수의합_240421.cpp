#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int dp[100001];
	// 초기화
	for (int i = 0; i <= N; i++) {
		dp[i] = i;
	}
	for (int i = 1; i <= N; i++) {

	}


	return 0;
}

// N에서 i의 제곱을 뺐을 때 0이 되지 않는 선에서
// 나올 수 있는 모든 개수 중 최소(min)가 되는 값 구하기
// d[i] = min( d[i], d[i - j * j] + 1) // +1 이유 : d[i - j * j]에서 제곱수를 한번 썼기 때문 