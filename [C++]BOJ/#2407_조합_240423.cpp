#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, m;
string arr[101][101];

string add(string num1, string num2) {
	int sum = 0;
	string result;

	// 1의 자리부터 더하기
	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty())
		{
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty())
		{
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}

	// 1의 자리부터 push 했으므로 뒤집긱
	reverse(result.begin(), result.end());

	return result;
}

string combi(int n, int m) {
	if (n == m || m == 0)
		return "1";
	string& result = arr[n][m]; // 참조형 변수

	// 이미 계산했으면 바로 return
	// 메모이제이션 기법
	if (result != "")
		return result;

	// 파스칼삼각형
	result = add(combi(n - 1, m - 1), combi(n - 1, m));

	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cout << combi(n, m);

	return 0;
}

// nCm = n-1Cm-1 + n-1Cm