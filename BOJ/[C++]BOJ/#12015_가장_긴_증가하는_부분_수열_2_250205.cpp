#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N; // ������ ũ��
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		// lower_bound�� ���� v.begin() ���� v.end() ���̿� num �̻��� ���� �����ϴ� ù��° �����͸� ����
		auto it = lower_bound(v.begin(), v.end(), num);
		if (it == v.end()) v.push_back(num); // �ִ��̸� �߰�
		else *it = num; // lower_bound �����Ϳ� num ���� ��ü
	}

	cout << v.size() << "\n";

	return 0;
}