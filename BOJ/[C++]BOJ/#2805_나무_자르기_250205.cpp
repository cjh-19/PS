/* �̺� Ž�� */

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll N, M; // ������ ��, ���������� ������ ��
ll low, high, mid, sum, hmax = -1; // ���� ���� ��, ū��, �߰���, �ڸ� ���� ��, H�� �ִ밪
ll tree[1000001]; // ���� �迭

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> tree[i];
	sort(tree, tree + N); // 0������ N������ �������� ����

	low = 0;
	high = tree[N - 1];

	// �� ���� ���� ������ -> ���ٸ� �� ������ hmax�̱� ����
	while (low <= high) {
		sum = 0; // �ڸ� ���� �� �ʱ�ȭ
		mid = (low + high) / 2;

		// �ڸ� ���� ���� ���ϱ�
		for (int i = 0; i < N; i++) {
			if (tree[i] > mid) sum += tree[i] - mid;
		}

		// �ڸ� ���� ���̰� �ʿ��� ���� �̻��� ���
		// low�� mid + 1�� ����
		if (sum >= M) {
			low = mid + 1;
			// H �ִ밪 ����
			if (mid > hmax) hmax = mid;
		}
		// �ʿ� ���̸� ���� ���ϴ� ��� high�� ���� -> �鳯�� ����
		else high = mid - 1;
	}

	cout << hmax;

	return 0;
}