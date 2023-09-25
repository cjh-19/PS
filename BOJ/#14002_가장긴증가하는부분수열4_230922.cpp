#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	vector<int> arr;
	vector<vector<int>> vt(1001);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	for (int i = 0; i < N; i++) {
		int j;
		for (j = 0; j < i; j++) {
			if (arr[i] > arr[j] && vt[i].size() < vt[j].size()) {
				vt[i].push_back(arr[j]);
			}
		}
		vt[i].push_back(arr[j]);
	}
	int max = 0, maxnum = 0;;
	for (int i = 0; i < N; i++) {
		if (max < vt[i].size()) {
			max = vt[i].size();
			maxnum = i;
		}
	}
	cout << max << "\n";
	for (int i = 0; i < vt[maxnum].size(); i++) {
		cout << vt[maxnum][i] << " ";
	}

	return 0;
}

// 5 3 1 2 7 �� ���ڷ� �޾��� �� 5 2 7 �� ��µǴ� ������ �𸣰���
// ���� ��Ȯ�� �� ������ ������ �� -> �ڵ��� ������ �ٽ� ¥���� �� ��