#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	// n������ ��� ������ �ִ� 5�� ����
	int start = n / 5;
	int remain = (n - start * 5) % 2; // 5���� �ִ��� ���� ��, ������ ���� 2������ ���� �� �ִ��� Ȯ��
	while (remain != 0) { // 2������ �Ž��� �� ���� ���
		if (start == 0) { // 5���� �Ѱ��� ������� ���� ���
			cout << -1; // �Ž��� �� ���� ��� �̹Ƿ� -1 ���
			return 0;
		}
		start -= 1; // 5���� �Ѱ� ����
		remain = (n - start * 5) % 2;
		// 5���� �ִ��� ����� �� ���� ������ ���� ���� �ݺ�
	}
	cout << start + (n - start * 5) / 2;

	return 0;
}