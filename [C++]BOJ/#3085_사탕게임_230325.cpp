#include<iostream>
#include<algorithm>

using namespace std;

// 최대 길이 (초기값은 문자 하나이므로 1)
int maxCount = 1;

// 열 체크
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

// 행 체크
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
	// 끝부분이 같아서 count를 늘렸을때,
	//  다음 비어있는 곳과 비교해서 다르다는 것을 체크하고
	//  maxCount를 최신화하기 위해서 크기를 51로 지정
	char arr[51][51];

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	// 완전 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			// 가로 스위칭
			swap(arr[i][j], arr[i][j + 1]);

			ColumnCheck(arr, N);
			LowCheck(arr, N);

			swap(arr[i][j], arr[i][j + 1]); // 원복

			// 세로 스위칭
			swap(arr[j][i], arr[j + 1][i]);

			ColumnCheck(arr, N);
			LowCheck(arr, N);

			swap(arr[j][i], arr[j + 1][i]); // 원복
			;
		}
	}

	cout << maxCount << endl;

	return 0;
}