#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int num;
	cin >> num;
	vector<int> dp;
	dp.push_back(1);
	dp.push_back(2);
	for (int i = 2; i < num; i++) {
		dp.push_back((dp[i - 1] + dp[i - 2]) % 10007);
	}
	cout << dp[num - 1] << "\n";

	return 0;
}

// 해설
// 1) 타일의 길이가 n-1 에서 n으로 1 증가 하는 경우
// n-1의 길이의 타일에 타일을 세로로 하나만 세우는 경우의 수만 존재한다.
// 이는 타일의 길이가 n-1일 때 경우의 수 인 dp[n-1]에 타일을 하나 붙이는 경우의 수이다. > 따라서 경우의 수는 dp[n-1]

// 2) 타일의 길이가 n-2 에서 n으로 2 증가 하는 경우
// n-2의 길이의 타일에 타을을 가로로 두개 겹쳐서 세우는 경우의 수만 존재한다.
// 세로로 길게 놓는 경우의 수는 (1)번의 경우의 수에 해당되기 때문에 고려하지 않는다.
// 따라서 이때 모든 경우의 수는 n-2일 때 경우의 수 인 dp[n-2]번이다.

// 따라서 타일의 길이가 n일 때의 경우의 수는 n-1일때 경우의 수와 n-2일때 경우의 수의 합과 같다.
// 결국 다음과 같은 점화식을 세울 수 있다. "dp[n] = dp[n-1] + dp[n-2]"