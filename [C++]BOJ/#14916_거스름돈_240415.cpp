#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	// ���� 5�� ���
	int start = n / 5;
	int remain = (n - start * 5) % 2; // 5���� �ΰ��� ���� ��, ¦������ Ȧ������
	while (remain != 0) { // 2������ ������ �� 0�� �ƴϸ�, 2������ �Ž����� x
		if (start == 0) { // 5�� ������ ����
			cout << -1;
			return 0;
		}

	}

	return 0;
}