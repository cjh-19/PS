#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	// n원에서 사용 가능한 최대 5원 개수
	int start = n / 5;
	int remain = (n - start * 5) % 2; // 5원을 최대한 뺐을 때, 나머지 돈을 2원으로 나눌 수 있는지 확인
	while (remain != 0) { // 2원으로 거스를 수 없는 경우
		if (start == 0) { // 5원을 한개도 사용하지 않은 경우
			cout << -1; // 거스를 수 없는 경우 이므로 -1 출력
			return 0;
		}
		start -= 1; // 5원을 한개 줄임
		remain = (n - start * 5) % 2;
		// 5원을 최대한 사용할 수 있을 때까지 위의 과정 반복
	}
	cout << start + (n - start * 5) / 2;

	return 0;
}