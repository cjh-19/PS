#include<iostream>
#include<algorithm>

using namespace std;

// �ִ� ���� (�ʱⰪ�� ���� �ϳ��̹Ƿ� 1)
int maxCount = 1;

// �� üũ
void ColumnCheck(char arr[51][51], int size) {
	for (int i = 0; i < size; i++) {
		int count = 1;
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				count++;
			}
			else {
				if (count > maxCount) {
					maxCount = count;
				}
				count = 1;
			}
		}
	}
	return;
}

// �� üũ
void LowCheck(char arr[51][51], int size) {
	for (int i = 0; i < size; i++) {
		int count = 1;
		for (int j = 0; j < size; j++) {
			if (arr[j][i] == arr[j + 1][i]) {
				count++;
			}
			else {
				if (count > maxCount) {
					maxCount = count;
				}
				count = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	int N;
	// ���κ��� ���Ƽ� count�� �÷�����,
	//  ���� ����ִ� ���� ���ؼ� �ٸ��ٴ� ���� üũ�ϰ�
	//  maxCount�� �ֽ�ȭ�ϱ� ���ؼ� ũ�⸦ 51�� ����
	char arr[51][51];

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	// ���� Ž��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			// ���� ����Ī
			swap(arr[i][j], arr[i][j + 1]);

			ColumnCheck(arr, N);
			LowCheck(arr, N);

			swap(arr[i][j], arr[i][j + 1]); // ����

			// ���� ����Ī
			swap(arr[j][i], arr[j + 1][i]);

			ColumnCheck(arr, N);
			LowCheck(arr, N);

			swap(arr[j][i], arr[j + 1][i]); // ����
			;
		}
	}

	cout << maxCount << endl;

	return 0;
}