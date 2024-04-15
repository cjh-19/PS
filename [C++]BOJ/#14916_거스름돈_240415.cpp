#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	// 먼저 5원 사용
	int start = n / 5;
	int remain = (n - start * 5) % 2; // 5원을 두개로 뺐을 때, 짝수인지 홀수인지
	while (remain != 0) { // 2원으로 나눴을 때 0이 아니면, 2원으로 거스리기 x
		if (start == 0) { // 5원 이하의 숫자
			cout << -1;
			return 0;
		}

	}

	return 0;
}