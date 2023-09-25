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

// 5 3 1 2 7 을 인자로 받았을 때 5 2 7 이 출력되는 이유를 모르겠음
// 논리상 정확한 것 같은데 이유를 모름 -> 코드의 구조를 다시 짜야할 듯 함