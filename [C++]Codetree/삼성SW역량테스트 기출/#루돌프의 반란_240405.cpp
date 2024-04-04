#include<iostream>

using namespace std;

#define MAX_N 51 // �ִ� ���� �� ũ��
#define MAX_P 31 // �ִ� ��Ÿ ��

int	n, m, p, c, d;
int point[MAX_P]; // ��Ÿ�� ����
pair<int, int> rudolf; // �絹�� ��ǥ
pair<int, int> santa[MAX_P]; // ��Ÿ ��ǥ

int board[MAX_N][MAX_N]; // ���� �� �絹�� ��Ÿ ��ǥ
bool alive[MAX_P]; // ��Ÿ ���� ����
int stun[MAX_P]; // ��Ÿ ���� ���� �ϼ�

// {��, ��, ��, ��}
const int dx[4] = { -1, 0, 1, 0 }; // �¿� ���� ����
const int dy[4] = { 0, 1, 0, -1 }; // ���� ���� ����

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

	for (int i = 1; i <= p; i++) {
		int id; // ��Ÿ ��ȣ
		cin >> id;
		cin >> santa[id].first >> santa[id].second; // ��Ÿ ��ǥ �Է�
		board[santa[id].first][santa[id].second] = id; // ���忡 ��Ÿ ��ġ ǥ��
		alive[id] = true; // ��Ÿ ���� ����
	}

	// ���� �ϼ� ��ŭ ����
	for (int i = 1; i <= m; i++) {
		// ù����δ� �絹���� ���� ����� ��Ÿ ã�� (��, ���� ��Ÿ����)
		int closestX = 10000, closestY = 10000, closestIdx = 0;

		// ����ִ� ��Ÿ �� �絹���� ���� ����� ��Ÿ�� ã��
		for (int j = 1; j <= p; j++) {
			if (!alive[j]) continue; // ��Ÿ�� ������� �ʴٸ�, �Ʒ� ���� ��ŵ

			// currentBest : ������ ���� ����� ��Ÿ�� �絹���� �Ÿ�
			// currentValue : ����ִ� ��Ÿ��� �絹���� �Ÿ�
			pair<int, pair<int, int>> currentBest = { (closestX - rudolf.first) * (closestX - rudolf.first) + (closestY - rudolf.second) * (closestY - rudolf.second), {-closestX, -closestY} };
			pair<int, pair<int, int>> currentValue = { (santa[j].first - rudolf.first) * (santa[j].first - rudolf.first) + (santa[j].second - rudolf.second) * (santa[j].second - rudolf.second), {-santa[j].first, -santa[j].second} };

			// ���� ����� ��Ÿ ��ȣ�� ��Ÿ ��ǥ ������Ʈ
			if (currentBest > currentValue) {
				closestX = santa[j].first;
				closestY = santa[j].second;
				closestIdx = j;
			}
		}

		// (���� ����� ��Ÿ�� �ִٸ�) 
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
				// ���� �̵��� ������ ��Ÿ�� �̵� ��ǥ ���� : (firstX, firstY)
				int firstX = closestX + moveX * c; // c��ŭ moveX �������� �̵�
				int firstY = closestY + moveY * c; // c��ŭ moveY �������� �̵�

				// ���� �̵��� ������ ��Ÿ�� ������ �������� : (lastX, lastY)
				int lastX = firstX;
				int lastY = firstY;

				stun[closestIdx] = i + 1; // �ε��� ��Ÿ�� i+1 ��° �ϱ��� ����

				// ��Ÿ�� �浹�Ͽ� �̵��� ���, ��Ÿ�� ���������� ������ �� �ִ� ��ġ
				// 1. ��ġ�� ���峻�� �ְ� 2. �� ĭ�� ��Ÿ�� ���� ��
				while (is_inrange(lastX, lastY) && board[lastX][lastY] > 0) {
					lastX += moveX;
					lastY += moveY;
				}

				// (lastX, lastY) ��ġ���� ���������� ��Ÿ�� �̵�
				// (lastX, lastY)�� (firstX, firstY)�� ������ ������ �ݺ�
				while (!(lastX == firstX && lastY == firstY)) {
					// ��Ÿ�� �̵��ϱ� ���� ��ġ
					int beforeX = lastX - moveX;
					int beforeY = lastY - moveY;

					// �̵��ϱ� ���� ��ġ�� ���� ���̶�� whlie�� ����
					// ���� �̵��� ������ ��踦 �Ѿ�� ���� ����
					if (!is_inrange(beforeX, beforeY)) break;

					// �̵��ϱ� ���� ��ġ�� �ִ� ��Ÿ ��ȣ
					int idx = board[beforeX][beforeY];

					// �̵��� ���� ��ġ�� ���� ���� ���̶��, ��Ÿ ����
					if (!is_inrange(lastX, lastY)) {
						alive[idx] = false;
					}
					else {
						// ��Ÿ�� ��ȣ�� �̵� ���� ĭ���� ����
						board[lastX][lastY] = board[beforeX][beforeY];
						santa[idx] = { lastX, lastY }; // ��Ÿ�� ��ǥ ������Ʈ
					}

					// �浹 ���������� �̵����̹Ƿ� ���� ��ǥ�� ������Ʈ
					lastX = beforeX;
					lastY = beforeY;
				}

				// �絹���� �浹�� �絹���� ���� ����� ��Ÿ ���� �߰�
				point[closestIdx] += c;
				santa[closestIdx] = { firstX, firstY }; // ù��° �浹 ��Ÿ ��ġ ������Ʈ
				if (is_inrange(firstX, firstY)) {
					board[firstX][firstY] = closestIdx; // �̵��� ĭ���� ��Ÿ ��ȣ ����
				}
				else { // �̵��� ��ǥ�� ���� ���̸� ��Ÿ ����
					alive[closestIdx] = false;
				}

			}
		}
		board[rudolf.first][rudolf.second] = -1; // �絹�� �̵� �� ��ǥ ����

		// �� ��Ÿ���� �絹���� ���� ����� �������� ��ĭ �̵�
		for (int j = 1; j <= p; j++) {
			// ��Ÿ�� ����ְų� ������ �ƴ϶��
			if (!alive[j] || stun[j] >= i)
				continue;

			// �Ÿ� ���
			// ���� ��ġ�� �絹������ �Ÿ�
			int minDistance = (santa[j].first - rudolf.first) * (santa[j].first - rudolf.first) + (santa[j].second - rudolf.second) * (santa[j].second - rudolf.second);
			// �̵��� ����(����)
			int moveDir = -1;

			// �絹���� ���� ����� �������� �̵��ϱ� ���� ���� Ž��(�����¿�)
			for (int dir = 0; dir < 4; dir++) {
				int nx = santa[j].first + dx[dir]; // ��/��
				int ny = santa[j].second + dy[dir]; // ��/��

				// �̵��� ��ġ�� ���� ���� ���̰ų�
				// �̵��� ��ġ�� ��Ÿ�� �ִ� ���� ��ŵ 
				if (!is_inrange(nx, ny) || board[nx][ny] > 0)
					continue;

				// �̵��� �Ÿ��� �絹������ �Ÿ�
				int dist = (nx - rudolf.first) * (nx - rudolf.first) + (ny - rudolf.second) * (ny - rudolf.second);
				if (dist < minDistance) {
					minDistance = dist;
					moveDir = dir;
				}
			}

			// �̵��� �� �־ moveDir�� ������Ʈ �� ���
			// ��Ÿ �̵�
			if (moveDir != -1) {
				// {nx, ny} : �̵��� ��Ÿ ��ǥ
				int nx = santa[j].first + dx[moveDir];
				int ny = santa[j].second + dy[moveDir];

				// ��Ÿ�� �̵����� �絹���� �浹�� ���
				if (nx == rudolf.first && ny == rudolf.second) {
					stun[j] = i + 1; // i+1�ϱ��� ����

					// �ðܳ��� �¿�/���� ����
					int moveX = -dx[moveDir];
					int moveY = -dy[moveDir];

					// d��ŭ �ðܳ��� ��ǥ
					int firstX = nx + moveX * d;
					int firstY = ny + moveY * d;

					int lastX = firstX;
					int lastY = firstY;

					if (d == 1) { // d = 1 �̶�� ��Ÿ�� ���ڸ��� ���ƿ�
						point[j] += d;
					}
					else {
						// ���� �̵��� ��ġ�� ��Ÿ�� �ִ� ���
						// �������� �̵�
						// (lastX, lastY) : ���������� �浹�� ��Ÿ�� ���� ��ġ
						while (is_inrange(lastX, lastY) && board[lastX][lastY] > 0) {
							lastX += moveX;
							lastY += moveY;
						}

						// �浹�� �Ͼ ������ ��Ÿ����
						// ó������ �ε��� ��Ÿ���� �������� ��ĭ�� �̵�
						while (!(lastX == firstX && lastY == firstY)) {
							// �̵� �� ��Ÿ ��ǥ
							int beforeX = lastX - moveX;
							int beforeY = lastY - moveY;

							// �̵����� ���� ���� �ٱ��� �־��ٸ� while�� ����
							if (!is_inrange(beforeX, beforeY))
								break;

							// �̵� �� ��ġ�� �ִ� ��Ÿ ��ȣ
							int idx = board[beforeX][beforeY];

							// �̵� ���� ��ġ�� ���� ���̶�� ��Ÿ ����
							if (!is_inrange(lastX, lastY)) {
								alive[idx] = false;
							}
							else { // ��Ÿ�� ��ǥ ������Ʈ
								board[lastX][lastY] = board[beforeX][beforeY];
								santa[idx] = { lastX, lastY };
							}

							// ���� ��Ÿ ���
							lastX = beforeX;
							lastY = beforeY;
						}

						// ù��°�� �ε��� ��Ÿ ��ǥ ������Ʈ
						point[j] += d; // ó�� �ε��� ��Ÿ ���� �߰�
						board[santa[j].first][santa[j].second] = 0; // ó�� �ε��� ��Ÿ �̵� �� ��ġ �ʱ�ȭ
						santa[j] = { firstX, firstY };
						if (is_inrange(firstX, firstY)) {
							board[firstX][firstY] = j;
						}
						else {
							alive[j] = false;
						}
					}
				}
				else { // ��ĭ �̵��� ��Ÿ ��ǥ ������Ʈ
					board[santa[j].first][santa[j].second] = 0;
					santa[j] = { nx, ny };
					board[nx][ny] = j;
				}
			}
		}

		// �� ���尡 ������ Ż������ ���� ��Ÿ���� 1�� ����
		for (int j = 1; j <= p; j++) {
			if (alive[j]) {
				point[j]++;
			}
		}
	}

	for (int i = 1; i <= p; i++) {
		cout << point[i] << " ";
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