#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, m;
string arr[101][101];

string add(string num1, string num2) {
	int sum;
	string result;

	// 1�� �ڸ����� ���ϱ�

	return result;
}

string combi(int n, int m) {
	if (n == m || m == 0)
		return "1";
	string& result = arr[n][m]; // ������ ����

	// �̹� ��������� �ٷ� return
	// �޸������̼� ���
	if (result != "")
		return result;

	// �Ľ�Į�ﰢ��

	return result;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	cout << combi(n, m);

	return 0;
}

// nCm = n-1Cm-1 + n-1Cm