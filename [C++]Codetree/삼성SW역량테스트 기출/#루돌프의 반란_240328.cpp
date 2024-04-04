#include<iostream>

using namespace std;

#define MAX_N 51 // �ִ� ���� �� ũ��
#define MAX_P 31 // �ִ� ��Ÿ ��

int	n, m, p, c, d;
pair<int, int> rudolf; // �絹�� ��ǥ
pair<int, int> santa[MAX_P]; // ��Ÿ ��ǥ

int board[MAX_N][MAX_N]; // ���� �� �絹�� ��Ÿ ��ǥ
bool alive[MAX_P]; // ��Ÿ ���� ����
int stun[MAX_P]; // ��Ÿ ���� ���� �ϼ�

// (x, y)�� ���� ���� ��ǥ���� Ȯ���ϴ� �Լ�
bool is_inrange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m >> p >> c >> d; // �ʱ� ���� ��
	cin >> rudolf.first >> rudolf.second; // �絹�� ��ǥ �Է�
	board[rudolf.first][rudolf.second] = -1; // ���忡 �絹�� ��ġ ǥ��

	for (int i = 0; i < p; i++) {
		int id; // ��Ÿ ��ȣ
		cin >> id;
		cin >> santa[id].first >> santa[id].second; // ��Ÿ ��ǥ �Է�
		board[santa[id].first][santa[id].second] = id; // ���忡 ��Ÿ ��ġ ǥ��
		alive[id] = true; // ��Ÿ ���� ����
	}

	// ���� �ϼ� ��ŭ ����
	for (int i = 0; i < m; i++) {
		// ù����δ� �絹���� ���� ����� ��Ÿ ã�� (��, ���� ��Ÿ����)
		int closestX = 10000, closestY = 10000, closestIdx = 0;

		// ����ִ� ��Ÿ �� �絹���� ���� ����� ��Ÿ�� ã��
		for (int j = 1; j <= p; j++) {
			if (!alive[j]) continue; // ��Ÿ�� ������� �ʴٸ�, �Ʒ� ���� ��ŵ

			// currentBest : ������ ���� ����� ��Ÿ�� �絹���� �Ÿ�
			// currentValue : ����ִ� ��Ÿ��� �絹���� �Ÿ�
			pair<int, pair<int, int>> currentBest = { (closestX - rudolf.first) * (closestX - rudolf.first) - (closestY - rudolf.second) * (closestY - rudolf.second), {-closestX, -closestY} };
			pair<int, pair<int, int>> currentValue = { (santa[j].first - rudolf.first) * (santa[j].first - rudolf.first) - (santa[j].second - rudolf.second) * (santa[j].second - rudolf.second), {-santa[j].first, -santa[j].second} };

			// ���� ����� ��Ÿ ��ȣ�� ��Ÿ ��ǥ ������Ʈ
			if (currentBest > currentValue) {
				closestX = santa[j].first;
				closestY = santa[j].second;
				closestIdx = j;
			}
		}

		// ���� ����� ��Ÿ�� �������� �絹���� �̵�
		if (closestIdx) {
			pair<int, int> prevRudolf = rudolf;

			// �絹���� �̵������� üũ (��� �������� �浹���� ���)
			int moveX = 0;
			if (closestX > rudolf.first) moveX = 1;
			else if (closestX < rudolf.first) moveX = -1;

			int moveY = 0;
			if (closestY > rudolf.second) moveY = 1;
			else if (closestY < rudolf.second) moveY = -1;

			// �絹�� ��ġ ������Ʈ
			rudolf.first += moveX;
			rudolf.second += moveY;
			board[prevRudolf.first][prevRudolf.second] = 0; // ���� �絹�� ��ġ 0���� �ʱ�ȭ

			// �絹���� �̵� -> ��Ÿ �浹 -> ��Ÿ �̵�
			if (rudolf.first == closestX && rudolf.second == closestY) {
				int firstX = closestX + moveX * c; // c��ŭ moveX �������� �̵�
				int firstY = closestY + moveY * c; // c��ŭ moveY �������� �̵�

				// ���� �浹 ��� ����
				int lastX = firstX;
				int lastY = firstY;

				stun[closestIdx] = i + 1; // �ε��� ��Ÿ�� i+1 ��° �ϱ��� ����

				// ���������� �浹�� �Ͼ ���� ������ ��ġ���� �����ؼ�
				// ���������� �����ǿ� �ִ� ��Ÿ�� ��ĭ�� �̵�
				while (!(lastX == firstX && lastY == firstY)) {
					int beforeX = lastX - moveX;
					int beforeY = lastY - moveY;

					if (!is_inrange(beforeX, beforeY)) break; // �̵��� ��Ÿ�� ���峻�� �ִٸ�

					int idx = board[beforeX][beforeY];

					//
					if (!is_inrange(lastX, lastY)) {
						alive[idx] = false;
					}
				}
			}
		}
	}


	return 0;
}


/*
**����

�� �Ͽ� ���� ����ִ� ��Ÿ �߿��� �絹���� ���� ����� ��Ÿ�� ã�� �絹���� �̵�

�̶� �Ÿ��� ��ư ��� ��ǥ�� ������ ����

��Ÿ�� �絹���� �浹�ϸ� ��Ÿ�� ������ ��� �絹�� �̵� �������� Ư�� ĭ��ŭ �з���.
�ش� ĭ�� �ٸ� ��Ÿ�� ������ �������� �̵�

��Ÿ�� �ڽ��� ���ʿ� �絹���� ���� ������� �� �ִ� �������� �̵�

�̵� �� �絹���� �浹�ϸ� �ݴ� �������� �и���, ������ �̵�

������ �� ���� ���� �� ��Ƴ��� ��Ÿ���� �߰� ���� �ο�

������ ��� ���� ����ǰų� ��� ��Ÿ�� Ż���� �� ����



** �˰���

�絹���� ��Ÿ�� �̵� �� �浹 ó��
���� ���
��Ÿ�� ���� �� ���� Ż�� ����
�� Ȯ���ϸ� ���������� ������ ���� ������Ʈ

�迭�� �ݺ����� Ȱ���� �� ��Ÿ�� ��ġ, �絹���� ��ġ, ���� ��  ������ ���� ����

��ü ������ �� ����ŭ �ݺ����� �����ϹǷ�
�ð� ���⵵�� �ùķ��̼��� �����ϴ� �κп��� �߻��ϴ� ��� -> O(M)
M�� ������ �� ��

*/